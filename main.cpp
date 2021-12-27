#include "controller-examples/WeatherController.h"

#include <iostream>
#include "RESTBuilder.h"

// No inheritance!
class interceptor {
public:
    restbuilder::http::HTTPResponse intercept(restbuilder::http::HTTPRequest& request, restbuilder::http::interceptor::HTTPInterceptorChain& chain) {
        std::cout << "Hello from chain!" << std::endl;
        return chain.next(request);
    }
};

int main() {
    WeatherController weatherController;

    interceptor inter;
    interceptor inter2;
    restbuilder::RESTBuilder::builder()->addController(weatherController)->addInterceptor(inter)->addInterceptor(inter2)->build();
    for(;;) {

    }
    return 0;
}