#include "controller-examples/WeatherController.h"

#include "RESTBuilder.h"

// TODO: Can we use pimpl?

int main() {
    WeatherController weatherController;

    RESTBuilder::builder()->addController(weatherController)->build();
    for(;;) {

    }
    return 0;
}