#include <boost/asio.hpp>
#include "socket/SocketManager.h"
#include "controller-examples/WeatherController.h"
#include "dispatch/Dispatcher.h"
using namespace boost::asio;

// TODO: Can we use pimpl?

int main() {
    WeatherController weatherController;
    Dispatcher::getDispatcher().registerController(weatherController);

    SocketManager manager(ip::tcp::endpoint(ip::tcp::v4(), 80));
    for(;;) {

    }
    return 0;
}