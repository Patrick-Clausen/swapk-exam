//
// Created by Patrick Clausen on 23/12/2021.
//

#include "RESTBuilder.h"

#include <utility>

using namespace restbuilder;

RESTBuilder RESTBuilder::builder() {
    return RESTBuilder();
}

RESTBuilder&
RESTBuilder::addException(const std::type_index& type, std::string_view statusCode, std::string_view statusMessage) {
    _exceptionHandler->addException(type, statusCode, statusMessage);
    return *this;
}

RESTBuilder& RESTBuilder::setEndpoint(boost::asio::ip::tcp::endpoint endpoint) {
    _endpoint = std::move(endpoint);
    return *this;
}

REST RESTBuilder::build() {
    return REST(_exceptionHandler, _dispatcher, _interceptor, _endpoint);
}



