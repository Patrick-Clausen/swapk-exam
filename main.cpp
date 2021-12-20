#include <boost/asio.hpp>
#include "socket/SocketManager.h"

using namespace boost::asio;


const std::string input =
        "POST / HTTP/1.1\nHost: localhost\nUser-Agent: curl/7.55.1\nAccept: /\nContent-Length: 5\nContent-Type: application/x-www-form-urlencoded\n\n{\nTemperature: 5\nCountry: Denmark\n}";

int main() {

    SocketManager manager(ip::tcp::endpoint(ip::tcp::v4(), 80));
    for(;;) {

    }
    return 0;
}