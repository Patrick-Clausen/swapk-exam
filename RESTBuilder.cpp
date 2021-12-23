//
// Created by Patrick Clausen on 23/12/2021.
//

#include "RESTBuilder.h"

RESTBuilder *RESTBuilder::builder() {
    return new RESTBuilder();
}

RESTBuilder *
RESTBuilder::addException(const std::type_index &type, std::string_view statusCode, std::string_view statusMessage) {
    _exceptionHandler.addException(type, statusCode, statusMessage);
    return this;
}

RESTBuilder *RESTBuilder::setEndpoint(boost::asio::ip::tcp::endpoint endpoint) {
    _endpoint = endpoint;
    return this;
}

void RESTBuilder::build() {
    _httpCallHandlerImpl = new HTTPCallHandlerImpl(_exceptionHandler, _dispatcher);
    std::function<std::string(std::string)> lambda = [this](std::string arg) -> std::string { return _httpCallHandlerImpl->handle(arg); };
    _socketManager = new SocketManager(_endpoint,
                                       lambda);
}



