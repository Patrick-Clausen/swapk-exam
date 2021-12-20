//
// Created by Patrick Clausen on 20/12/2021.
//

#ifndef SWAPK_EXAM_HTTPCALLHANDLER_H
#define SWAPK_EXAM_HTTPCALLHANDLER_H

#include <iostream>
#include "HttpCallParser.h"
#include "../dispatch/Dispatcher.h"

namespace http::call {
    static std::string handleCall(std::string& request) {
        HttpRequest parsedRequest = HttpCallParser::ParseCallToRequest(request);

        HttpResponse response = Dispatcher::dispatch(parsedRequest);

        std::stringstream ss;

        ss << response;

        return ss.str();
    }
}

#endif //SWAPK_EXAM_HTTPCALLHANDLER_H
