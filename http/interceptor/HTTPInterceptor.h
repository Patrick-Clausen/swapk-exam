//
// Created by Patrick Clausen on 23/12/2021.
//

#ifndef SWAPK_EXAM_HTTPINTERCEPTOR_H
#define SWAPK_EXAM_HTTPINTERCEPTOR_H

#include <functional>
#include <variant>
#include <vector>

#include "../../dispatch/detect.h"
#include "../../dispatch/Dispatcher.h"
#include "hasIntercept.h"

#include "../HTTPRequest.h"
#include "../HTTPResponse.h"


class HTTPInterceptorChain {
public:
    typedef std::function<HTTPResponse (HTTPRequest &, HTTPInterceptorChain &)> HTTPInterceptor;

    template<typename T, typename... Args>
    explicit HTTPInterceptorChain(Dispatcher &dispatcher, T arg, Args... args) {
        addInterceptor(arg);
        HTTPInterceptorChain(dispatcher, args...);
    }

    template<typename T>
    explicit HTTPInterceptorChain(Dispatcher &dispatcher, T arg)
            : _dispatcher(dispatcher) {
        addInterceptor(arg);
    }

    explicit HTTPInterceptorChain(Dispatcher &dispatcher): _dispatcher(dispatcher) { }

    HTTPResponse callChain(HTTPRequest &request) {
        HTTPInterceptorChain chain(*this);

        return chain.next(request);
    }

    HTTPResponse next(HTTPRequest &request) {
        if (_iterator == _interceptors.end()) {
            return _dispatcher.dispatch(request);
        }
        return (*(_iterator++))(request, *this);
    }

    template<typename T>
    void addInterceptor(T interceptor) {
        static_assert(detect<hasIntercept, T, HTTPResponse (T::*)(HTTPRequest &, HTTPInterceptorChain &)>::value,
                      "Interceptor did not have valid intercept method");
        HTTPInterceptor inter = [&interceptor](HTTPRequest& req, HTTPInterceptorChain& chain)->HTTPResponse{
            return interceptor.intercept(req, chain);
        };
        _interceptors.push_back(inter);
    }


private:
    HTTPInterceptorChain(HTTPInterceptorChain &other) : _interceptors(other._interceptors), _dispatcher(other._dispatcher) {
        _iterator = _interceptors.begin();
    };
    std::vector<HTTPInterceptor> _interceptors;
    std::vector<HTTPInterceptor>::iterator _iterator;

    Dispatcher &_dispatcher;
};


#endif //SWAPK_EXAM_HTTPINTERCEPTOR_H
