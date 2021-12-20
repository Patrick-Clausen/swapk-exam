//
// Created by Patrick Clausen on 20/12/2021.
//

#ifndef SWAPK_EXAM_HTTPCALLHANDLER_H
#define SWAPK_EXAM_HTTPCALLHANDLER_H

#include <iostream>
#include "HTTPCallParser.h"
#include "../dispatch/Dispatcher.h"

namespace http::call {
    static std::string handleCall(std::string& request) {
        HTTPRequest parsedRequest = HTTPCallParser::parseRequest(request);

        HTTPResponse response = Dispatcher::dispatch(parsedRequest);

        return HTTPCallParser::stringifyResponse(response);
    }
}

#endif //SWAPK_EXAM_HTTPCALLHANDLER_H
