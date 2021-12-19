#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

std::string read(tcp::socket& socket) {
    char recv[1024];

    socket.receive(boost::asio::buffer(recv));
    std::string data = recv;
    return data;
}

int main() {
    boost::asio::io_context io_context;
    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 80));
    for (;;) {
        tcp::socket socket(io_context);
        acceptor.accept(socket);

        std::string message = read(socket);

        std::cout << message << std::endl;


    }


    std::cout << "Hello, World!" << std::endl;
    return 0;
}