//
// Created by Patrick Clausen on 22/12/2021.
//

#ifndef SWAPK_EXAM_HTTPCALLHANDLER_H
#define SWAPK_EXAM_HTTPCALLHANDLER_H

#include "../../exception/ExceptionHandler.h"
#include "../interceptor/HTTPInterceptor.h"
#include "../HTTPRequest.h"
#include "../HTTPResponse.h"

class HTTPCallHandler {
public:
    HTTPCallHandler(ExceptionHandler exceptionHandler, HTTPInterceptorChain& interceptorChain);

    std::string handle(const std::string &request);

    HTTPCallHandler() = delete;
private:


    std::string handleInInstance(const std::string &request);

    ExceptionHandler _exceptionHandler;
    HTTPInterceptorChain& _interceptorChain;
};


#endif //SWAPK_EXAM_HTTPCALLHANDLER_H
