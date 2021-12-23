//
// Created by Patrick Clausen on 19/12/2021.
//

#include "SocketManager.h"

#include <thread>
#include <chrono>

using namespace std::chrono_literals;
using namespace boost::asio;

SocketManager::SocketManager(ip::tcp::endpoint endpoint, std::function<std::string(std::string)> callHandler)
        :
        _callHandler(callHandler),
        _listener(new SocketListener(endpoint)),
        _thread(new std::thread(&SocketManager::threadFunction, this)) {
    _listener->getConnectionSignal().connect([this](auto &&socket) { newConnection(socket); });
}

SocketManager::~SocketManager() {
    delete _listener;

    _keepGoing = false;
    _thread->join();
    delete _thread;

    // Transfer all remaining connections
    while (transferConnection()) {}

    // Clean up all active connections, including the ones just transferred
    for (auto connection: _connections) {
        delete connection;
    }
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
    ip::tcp::socket *incomingSocket = nullptr;

    {
        const std::lock_guard<std::mutex> incomingLock(_incomingConnectionsMutex);

        if (!_incomingConnections.empty()) {
            incomingSocket = _incomingConnections.front();
            _incomingConnections.pop();
        }
    }

    if (incomingSocket == nullptr) {
        return false;
    }

    auto connection = new SocketConnection(incomingSocket, _callHandler);
    {
        const std::lock_guard<std::mutex> connectionLock(_connectionsMutex);

        _connections.push_back(connection);
    }
    connection->getCompletionSignal().connect([this](auto &&connection) { connectionCompleted(connection); });
    std::thread([connection]() { (*connection)(); }).detach();

    return true;
}

bool SocketManager::cleanupConnection() {
    SocketConnection *connectionToClean = nullptr;

    {
        const std::lock_guard<std::mutex> completedLock(_completedConnectionsMutex);

        if (!_completedConnections.empty()) {
            connectionToClean = _completedConnections.front();
            _completedConnections.pop();
        }
    }

    if (connectionToClean == nullptr) {
        return false;
    }

    {
        const std::lock_guard<std::mutex> connectionLock(_connectionsMutex);

        auto found = std::find(_connections.begin(), _connections.end(), connectionToClean);
        if (found != _connections.end()) {
            _connections.erase(found);
        }
    }
    delete connectionToClean;

    return true;
}

void SocketManager::newConnection(ip::tcp::socket *connection) {
    const std::lock_guard<std::mutex> lock(_incomingConnectionsMutex);

    _incomingConnections.push(connection);
}

void SocketManager::connectionCompleted(SocketConnection *connection) {
    const std::lock_guard<std::mutex> lock(_completedConnectionsMutex);

    _completedConnections.push(connection);
}
