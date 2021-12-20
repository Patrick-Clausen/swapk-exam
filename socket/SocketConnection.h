//
// Created by Patrick Clausen on 19/12/2021.
//

#ifndef SWAPK_EXAM_SOCKETCONNECTION_H
#define SWAPK_EXAM_SOCKETCONNECTION_H

#include <boost/signals2.hpp>
#include <boost/asio.hpp>

class SocketConnection {
public:
    SocketConnection(boost::asio::ip::tcp::socket* socket);
    ~SocketConnection();

    boost::signals2::signal<void(SocketConnection*)>& getCompletionSignal();

private:
    boost::asio::ip::tcp::socket* _socket;

    void threadFunction();
    std::thread _connectionThread;

    static std::string read(boost::asio::ip::tcp::socket& socket);
    static void write(boost::asio::ip::tcp::socket& socket, std::string message);

    boost::signals2::signal<void(SocketConnection*)> _completionSignal;
};


#endif //SWAPK_EXAM_SOCKETCONNECTION_H
