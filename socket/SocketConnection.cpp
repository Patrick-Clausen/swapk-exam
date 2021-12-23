//
// Created by Patrick Clausen on 19/12/2021.
//

#include "SocketConnection.h"
#include <iostream>

using namespace boost::asio;

SocketConnection::SocketConnection(ip::tcp::socket *socket, std::function<std::string(std::string)> &callHandler)
        : _callHandler(callHandler), _socket(socket) {}


void SocketConnection::connectionFunction() {
    std::string message = read(*_socket);

    std::string response = _callHandler(message);

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
    _socket->close();
    delete _socket;
}

boost::signals2::signal<void(SocketConnection *)> &SocketConnection::getCompletionSignal() {
    return _completionSignal;
}

void SocketConnection::operator()() {
    connectionFunction();
}

