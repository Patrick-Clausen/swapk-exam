//
// Created by Patrick Clausen on 22/12/2021.
//

#include "../HTTPCallParser.h"
#include "../../dispatch/Dispatcher.h"
#include "HTTPCallHandlerImpl.h"

http::details::call::HTTPCallHandlerImpl &http::details::call::HTTPCallHandlerImpl::handler() {
    static HTTPCallHandlerImpl handler;
    return handler;
}

std::string http::details::call::HTTPCallHandlerImpl::handle(const std::string& request) {
    return handler().handleInInstance(request);
}

std::string http::details::call::HTTPCallHandlerImpl::handleInInstance(const std::string& request) {
    HTTPResponse response;
    try {
        HTTPRequest parsedRequest = HTTPCallParser::parseRequest(request);

        response = Dispatcher::getDispatcher().dispatch(parsedRequest);
    } catch (std::exception& exception) {
        response = _exceptionHandler.handleException(exception);
    }

    return HTTPCallParser::stringifyResponse(response);
}
