//
// Created by Patrick Clausen on 20/12/2021.
//

#ifndef SWAPK_EXAM_HTTPCALLHANDLER_H
#define SWAPK_EXAM_HTTPCALLHANDLER_H

#include <iostream>
#include "HTTPCallParser.h"
#include "../dispatch/Dispatcher.h"
#include "details/HTTPCallHandlerImpl.h"

namespace http::call {

    static std::string handleCall(std::string& request) {
        return http::details::call::HTTPCallHandlerImpl::handle(request);
    }
}

#endif //SWAPK_EXAM_HTTPCALLHANDLER_H
