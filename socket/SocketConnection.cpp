//
// Created by Patrick Clausen on 19/12/2021.
//

#include "SocketConnection.h"
#include <iostream>

using namespace boost::asio;

SocketConnection::SocketConnection(std::shared_ptr<ip::tcp::socket> socket, std::function<std::string(std::string)> &callHandler)
        : _callHandler(callHandler), _socket(socket) {}

std::string SocketConnection::read(ip::tcp::socket &socket) {
    char recv[1024];

    socket.receive(buffer(recv));
    std::string data = recv;
    return data;
}

void SocketConnection::write(ip::tcp::socket &socket, std::string message) {
    boost::asio::write(socket, buffer(message));
}

SocketConnection::~SocketConnection() {
    _socket->close();
}

boost::signals2::signal<void(std::shared_ptr<SocketConnection> )> &SocketConnection::getCompletionSignal() {
    return _completionSignal;
}

void SocketConnection::operator()(std::shared_ptr<SocketConnection> callbackReference) {
    std::string message = read(*_socket);

    std::string response = _callHandler(message);

    write(*_socket, response);
    _completionSignal(callbackReference);
}

