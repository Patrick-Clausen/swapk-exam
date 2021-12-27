#include "controller-examples/WeatherController.h"

#include <iostream>
#include "RESTBuilder.h"

// No inheritance!
class interceptor {
public:
    HTTPResponse intercept(HTTPRequest& request, HTTPInterceptorChain& chain) {
        std::cout << "Hello from chain!" << std::endl;
        return chain.next(request);
    }
};

int main() {
    WeatherController weatherController;

    interceptor inter;
    interceptor inter2;
    RESTBuilder::builder()->addController(weatherController)->addInterceptor(inter)->addInterceptor(inter2)->build();
    for(;;) {

    }
    return 0;
}