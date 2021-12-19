//
// Created by claus on 17/12/2021.
//
#include <thread>
#include "SocketListener.h"

SocketListener::SocketListener(ip::tcp::endpoint endpoint)
        : _acceptor(_ioContext, endpoint) {}

void SocketListener::listen() {
    std::thread listener(&SocketListener::listenImpl, this);
}

void SocketListener::listenImpl() {

}
