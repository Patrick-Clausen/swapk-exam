//
// Created by Patrick Clausen on 17/12/2021.
//
#include <thread>
#include "SocketListener.h"

using namespace boost::asio;
using namespace restbuilder::socket;

SocketListener::SocketListener(const ip::tcp::endpoint& endpoint)
        : _acceptor(_ioContext, endpoint), _listener(&SocketListener::listenImpl, this) {}

void SocketListener::listenImpl() {
    while (_keepGoing) {
        std::shared_ptr<ip::tcp::socket> socket(new ip::tcp::socket(_ioContext));
        _acceptor.accept(*socket);

        _connectionSignal(socket);
    }
}

SocketListener::~SocketListener() {
    _keepGoing = false;
    _acceptor.close();
    _listener.join();
}

boost::signals2::signal<void(std::shared_ptr<ip::tcp::socket>)>& SocketListener::getConnectionSignal() {
    return _connectionSignal;
}
