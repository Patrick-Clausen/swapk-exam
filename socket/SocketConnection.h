//
// Created by Patrick Clausen on 19/12/2021.
//

#ifndef SWAPK_EXAM_SOCKETCONNECTION_H
#define SWAPK_EXAM_SOCKETCONNECTION_H

#include <string>
#include <functional>
#include <boost/signals2.hpp>
#include <boost/asio.hpp>

class SocketConnection {
public:
    SocketConnection(boost::asio::ip::tcp::socket* socket, std::function<std::string(std::string)>& callHandler);
    ~SocketConnection();

    void operator()();

    boost::signals2::signal<void(SocketConnection*)>& getCompletionSignal();

private:
    std::function<std::string(std::string)>& _callHandler;
    boost::asio::ip::tcp::socket* _socket;

    void connectionFunction();

    static std::string read(boost::asio::ip::tcp::socket& socket);
    static void write(boost::asio::ip::tcp::socket& socket, std::string message);

    boost::signals2::signal<void(SocketConnection*)> _completionSignal;
};


#endif //SWAPK_EXAM_SOCKETCONNECTION_H
