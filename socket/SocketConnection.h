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
    SocketConnection(std::shared_ptr<boost::asio::ip::tcp::socket> socket, std::function<std::string(std::string)>& callHandler);
    ~SocketConnection();

    void operator()(std::shared_ptr<SocketConnection> callbackReference);

    boost::signals2::signal<void(std::shared_ptr<SocketConnection>)>& getCompletionSignal();

private:
    std::function<std::string(std::string)>& _callHandler;
    std::shared_ptr<boost::asio::ip::tcp::socket> _socket;

    static std::string read(boost::asio::ip::tcp::socket& socket);
    static void write(boost::asio::ip::tcp::socket& socket, std::string message);

    boost::signals2::signal<void(std::shared_ptr<SocketConnection>)> _completionSignal;
};


#endif //SWAPK_EXAM_SOCKETCONNECTION_H
