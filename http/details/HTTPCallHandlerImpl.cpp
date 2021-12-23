//
// Created by Patrick Clausen on 22/12/2021.
//

#include "../HTTPCallParser.h"
#include "../../dispatch/Dispatcher.h"
#include "HTTPCallHandlerImpl.h"

std::string HTTPCallHandlerImpl::handle(const std::string &request) {
    return handleInInstance(request);
}

std::string HTTPCallHandlerImpl::handleInInstance(const std::string &request) {
    HTTPResponse response;
    try {
        HTTPRequest parsedRequest = HTTPCallParser::parseRequest(request);

        response = _dispatcher.dispatch(parsedRequest);
    } catch (std::exception &exception) {
        response = _exceptionHandler.handleException(exception);
    }

    return HTTPCallParser::stringifyResponse(response);
}

HTTPCallHandlerImpl::HTTPCallHandlerImpl(ExceptionHandler exceptionHandler,
                                                              Dispatcher dispatcher)
        : _exceptionHandler(exceptionHandler), _dispatcher(dispatcher) {

}
