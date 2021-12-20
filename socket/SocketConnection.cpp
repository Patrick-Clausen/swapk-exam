//
// Created by Patrick Clausen on 19/12/2021.
//

#include "SocketConnection.h"
#include "../http/HTTPCallHandler.h"
#include <iostream>

using namespace boost::asio;

SocketConnection::SocketConnection(ip::tcp::socket *socket)
        : _socket(socket), _connectionThread(&SocketConnection::threadFunction, this) {}


void SocketConnection::threadFunction() {
    std::string message = read(*_socket);

    std::string response = http::call::handleCall(message);

    write(*_socket, response);
    _completionSignal(this);
}

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
    _connectionThread.join();
    _socket->close();
    delete _socket;
}

boost::signals2::signal<void(SocketConnection *)> &SocketConnection::getCompletionSignal() {
    return _completionSignal;
}

