#include <boost/asio.hpp>
#include "SocketManager.h"

using namespace boost::asio;

int main() {
    SocketManager manager(ip::tcp::endpoint(ip::tcp::v4(), 80));
    for(;;) {

    }
    return 0;
}