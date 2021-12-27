#include "controller-examples/WeatherController.h"

#include <iostream>
#include "restbuilder/RESTBuilder.h"

// No inheritance!
class interceptor {
public:
    restbuilder::http::HTTPResponse
    intercept(restbuilder::http::HTTPRequest&& request, restbuilder::http::interceptor::HTTPInterceptorChain& chain) {
        std::cout << "Hello from chain!" << std::endl;
        return chain.next(std::move(request));
    }
};

int main() {
    WeatherController weatherController;

    interceptor inter;
    interceptor inter2;
    restbuilder::REST rest = restbuilder::RESTBuilder::builder()
            .addController(weatherController)
            .addInterceptor(inter)
            .addInterceptor(inter2)
            .build();

    for (;;) {
        // Builder doesn't block main thread to allow other uses, so we block it explicitly.
    }
    return 0;
}