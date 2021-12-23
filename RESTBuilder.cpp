//
// Created by Patrick Clausen on 23/12/2021.
//

#include "RESTBuilder.h"

#include <utility>

RESTBuilder *RESTBuilder::builder() {
    return new RESTBuilder();
}

RESTBuilder *
RESTBuilder::addException(const std::type_index &type, std::string_view statusCode, std::string_view statusMessage) {
    _exceptionHandler.addException(type, statusCode, statusMessage);
    return this;
}

RESTBuilder *RESTBuilder::setEndpoint(boost::asio::ip::tcp::endpoint endpoint) {
    _endpoint = std::move(endpoint);
    return this;
}

void RESTBuilder::build() {
    _httpCallHandler = new HTTPCallHandler(_exceptionHandler, _dispatcher);
    std::function<std::string(std::string)> lambda = [this](
            const std::string &arg) -> std::string { return _httpCallHandler->handle(arg); };
    _socketManager = new SocketManager(_endpoint,
                                       lambda);
}

RESTBuilder::~RESTBuilder() {
    delete _httpCallHandler;
    delete _socketManager;
}



