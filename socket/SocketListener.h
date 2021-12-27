//
// Created by Patrick Clausen on 17/12/2021.
//

#ifndef SWAPK_EXAM_SOCKETLISTENER_H
#define SWAPK_EXAM_SOCKETLISTENER_H

#include <boost/signals2.hpp>
#include <boost/asio.hpp>

class SocketListener {
public:
    explicit SocketListener(const boost::asio::ip::tcp::endpoint &endpoint);

    ~SocketListener();

    boost::signals2::signal<void(std::shared_ptr<boost::asio::ip::tcp::socket> )> &getConnectionSignal();

private:
    void listenImpl();

    boost::signals2::signal<void(std::shared_ptr<boost::asio::ip::tcp::socket> )> _connectionSignal;

    boost::asio::io_context _ioContext;
    boost::asio::ip::tcp::acceptor _acceptor;

    std::thread _listener;
    bool _keepGoing = true;
};


#endif //SWAPK_EXAM_SOCKETLISTENER_H
