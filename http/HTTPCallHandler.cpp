//
// Created by Patrick Clausen on 22/12/2021.
//

#include "HTTPCallParser.h"
#include "../dispatch/Dispatcher.h"
#include "HTTPCallHandler.h"

using namespace restbuilder::http;

std::string HTTPCallHandler::handle(std::string &&request) {
    HTTPResponse response;
    try {
        HTTPRequest parsedRequest = HTTPCallParser::parseRequest(request);

        response = _interceptorChain.callChain(parsedRequest);
    } catch (std::exception &exception) {
        response = _exceptionHandler.handleException(std::move(exception));
    }

    return std::move(HTTPCallParser::stringifyResponse(response));
}

HTTPCallHandler::HTTPCallHandler(exception::ExceptionHandler &exceptionHandler,
                                 interceptor::HTTPInterceptorChain &interceptorChain)
        : _exceptionHandler(exceptionHandler), _interceptorChain(interceptorChain) {

}
