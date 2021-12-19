//
// Created by claus on 17/12/2021.
//

#ifndef SWAPK_EXAM_SOCKETLISTENER_H
#define SWAPK_EXAM_SOCKETLISTENER_H

#include <boost/asio.hpp>

using namespace boost::asio;

class SocketListener {
public:
    SocketListener(ip::tcp::endpoint endpoint);
    void listen();
private:
    void listenImpl();

    io_context _ioContext;
    ip::tcp::acceptor _acceptor;
    std::mutex _listening;
};


#endif //SWAPK_EXAM_SOCKETLISTENER_H
