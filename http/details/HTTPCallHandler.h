//
// Created by Patrick Clausen on 22/12/2021.
//

#ifndef SWAPK_EXAM_HTTPCALLHANDLER_H
#define SWAPK_EXAM_HTTPCALLHANDLER_H

#include "../../exception/ExceptionHandler.h"
#include "../../dispatch/Dispatcher.h"
#include "../HTTPRequest.h"
#include "../HTTPResponse.h"

class HTTPCallHandler {
public:
    HTTPCallHandler(ExceptionHandler exceptionHandler, Dispatcher dispatcher);

    std::string handle(const std::string &request);

    HTTPCallHandler() = delete;
private:


    std::string handleInInstance(const std::string &request);

    ExceptionHandler _exceptionHandler;
    Dispatcher _dispatcher;
};


#endif //SWAPK_EXAM_HTTPCALLHANDLER_H
