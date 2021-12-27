//
// Created by Patrick Clausen on 19/12/2021.
//

#include "SocketManager.h"

#include <thread>
#include <chrono>
#include <utility>

using namespace std::chrono_literals;
using namespace boost::asio;

SocketManager::SocketManager(ip::tcp::endpoint endpoint, std::function<std::string(std::string)>& callHandler)
        :
        _callHandler(std::move(callHandler)),
        _listener(endpoint),
        _thread(&SocketManager::threadFunction, this) {
    _listener.getConnectionSignal().connect([this](auto &&socket) { newConnection(socket); });
}

SocketManager::~SocketManager() {
    _keepGoing = false;
    _thread.join();

    // Transfer all remaining connections
    while (transferConnection()) {}
}

void SocketManager::threadFunction() {
    while (_keepGoing) {
        // Let the thread sleep for a short while to reduce CPU load
        std::this_thread::sleep_for(5ms);

        // Transfer all available connections
        while (transferConnection()) {}

        // Clean up all completed connections
        while (cleanupConnection()) {}
    }
}

bool SocketManager::transferConnection() {
    std::shared_ptr<ip::tcp::socket> incomingSocket;

    {
        const std::lock_guard<std::mutex> incomingLock(_incomingConnectionsMutex);

        if (!_incomingConnections.empty()) {
            incomingSocket =_incomingConnections.front();
            _incomingConnections.pop();
        }
    }

    if (!incomingSocket) {
        return false;
    }

    std::shared_ptr<SocketConnection> connection(new SocketConnection(incomingSocket, _callHandler));
    {
        const std::lock_guard<std::mutex> connectionLock(_connectionsMutex);

        _connections.push_back(connection);
    }
    connection->getCompletionSignal().connect([this](auto &&connection) { connectionCompleted(connection); });
    std::thread([connection]() { (*connection)(connection); }).detach();

    return true;
}

bool SocketManager::cleanupConnection() {
    std::shared_ptr<SocketConnection> connectionToClean;

    {
        const std::lock_guard<std::mutex> completedLock(_completedConnectionsMutex);

        if (!_completedConnections.empty()) {
            connectionToClean = _completedConnections.front();
            _completedConnections.pop();
        }
    }

    if (!connectionToClean) {
        return false;
    }

    {
        const std::lock_guard<std::mutex> connectionLock(_connectionsMutex);

        auto found = std::find(_connections.begin(), _connections.end(), connectionToClean);
        if (found != _connections.end()) {
            _connections.erase(found);
        }
    }

    return true;
}

void SocketManager::newConnection(std::shared_ptr<ip::tcp::socket> connection) {
    const std::lock_guard<std::mutex> lock(_incomingConnectionsMutex);

    _incomingConnections.push(connection);
}

void SocketManager::connectionCompleted(std::shared_ptr<SocketConnection> connection) {
    const std::lock_guard<std::mutex> lock(_completedConnectionsMutex);

    _completedConnections.push(connection);
}
