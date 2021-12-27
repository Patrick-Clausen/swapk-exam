//
// Created by Patrick Clausen on 22/12/2021.
//

#ifndef SWAPK_EXAM_HTTPCALLHANDLER_H
#define SWAPK_EXAM_HTTPCALLHANDLER_H

#include "../exception/ExceptionHandler.h"
#include "interceptor/HTTPInterceptor.h"
#include "HTTPRequest.h"
#include "HTTPResponse.h"

namespace restbuilder::http {

    class HTTPCallHandler {
    public:
        HTTPCallHandler(exception::ExceptionHandler &exceptionHandler, interceptor::HTTPInterceptorChain &interceptorChain);

        std::string handle(std::string &&request);

        HTTPCallHandler() = delete;

    private:

        exception::ExceptionHandler &_exceptionHandler;
        interceptor::HTTPInterceptorChain &_interceptorChain;
    };
}

#endif //SWAPK_EXAM_HTTPCALLHANDLER_H
