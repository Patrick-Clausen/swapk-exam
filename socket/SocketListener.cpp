//
// Created by Patrick Clausen on 17/12/2021.
//
#include <thread>
#include "SocketListener.h"

using namespace boost::asio;

SocketListener::SocketListener(const ip::tcp::endpoint &endpoint)
        : _acceptor(_ioContext, endpoint) {
    _listener = new std::thread(&SocketListener::listenImpl, this);
}

void SocketListener::listenImpl() {
    while (_keepGoing) {
        auto* socket = new ip::tcp::socket(_ioContext);
        _acceptor.accept(*socket);

        _connectionSignal(socket);
    }
}

SocketListener::~SocketListener() {
    _keepGoing = false;
    _acceptor.close();
    _listener->join();
    delete _listener;
}

boost::signals2::signal<void(ip::tcp::socket *)>& SocketListener::getConnectionSignal() {
    return _connectionSignal;
}
