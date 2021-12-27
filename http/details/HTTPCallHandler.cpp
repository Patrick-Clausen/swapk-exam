//
// Created by Patrick Clausen on 22/12/2021.
//

#include "../HTTPCallParser.h"
#include "../../dispatch/Dispatcher.h"
#include "HTTPCallHandler.h"

#include <utility>

std::string HTTPCallHandler::handle(const std::string &request) {
    return handleInInstance(request);
}

std::string HTTPCallHandler::handleInInstance(const std::string &request) {
    HTTPResponse response;
    try {
        HTTPRequest parsedRequest = HTTPCallParser::parseRequest(request);

        response = _interceptorChain.callChain(parsedRequest);
    } catch (std::exception &exception) {
        response = _exceptionHandler.handleException(exception);
    }

    return HTTPCallParser::stringifyResponse(response);
}

HTTPCallHandler::HTTPCallHandler(ExceptionHandler exceptionHandler,
                                 HTTPInterceptorChain& interceptorChain)
        : _exceptionHandler(std::move(exceptionHandler)), _interceptorChain(interceptorChain) {

}
