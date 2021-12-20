//
// Created by Patrick Clausen on 19/12/2021.
//

#include "SocketConnection.h"

#include <iostream>

using namespace boost::asio;

SocketConnection::SocketConnection(ip::tcp::socket *socket)
        : _socket(socket), _connectionThread(&SocketConnection::threadFunction, this) {}


void SocketConnection::threadFunction() {
    std::string message = read(*_socket);

    std::cout << "READING FROM SOCKET AT ADDRESS: " << _socket << std::endl;
    std::cout << message << std::endl;

    std::cout << "REPLYING..." << std::endl;
    write(*_socket, "HTTP/1.1 200 OK\r\n\r\nHello\r\n");
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

