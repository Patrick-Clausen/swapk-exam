//
// Created by Patrick Clausen on 22/12/2021.
//

#ifndef SWAPK_EXAM_HTTPCALLHANDLERIMPL_H
#define SWAPK_EXAM_HTTPCALLHANDLERIMPL_H

#include "../../exception/ExceptionHandler.h"
#include "../../dispatch/Dispatcher.h"
#include "../HTTPRequest.h"
#include "../HTTPResponse.h"

class HTTPCallHandlerImpl {
public:
    HTTPCallHandlerImpl(ExceptionHandler exceptionHandler, Dispatcher dispatcher);

    std::string handle(const std::string &request);

    HTTPCallHandlerImpl() = delete;
private:


    std::string handleInInstance(const std::string &request);

    ExceptionHandler _exceptionHandler;
    Dispatcher _dispatcher;
};


#endif //SWAPK_EXAM_HTTPCALLHANDLERIMPL_H
