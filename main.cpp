#include <iostream>
#include "Dispathcer/Dispatcher.h"
#include "Controllers/WeatherController.h"

int main() {
    auto wc = WeatherController();
    auto d = Dispatcher();
    d.registerController(wc);
    d.dispatch("weather", "POST");

    return 0;
}