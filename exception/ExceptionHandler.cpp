//
// Created by Tue on 20/12/2021.
//

#include "ExceptionHandler.h"

#include "defaults/method_not_allowed_exception.h"
#include "defaults/parse_failure_exception.h"
#include "defaults/endpoint_not_found_exception.h"

void ExceptionHandler::addException(const std::type_index& type, std::string_view statusCode, std::string_view statusMessage) {
    HTTPResponse response;
    response.statusCode = statusCode;
    response.protocolVersion = ProtocolVersion::HTTP_1_1;
    response.statusMessage = statusMessage;
    _exceptionMapping.insert({type, response});
}

HTTPResponse ExceptionHandler::handleException(const std::exception& exception) {
    auto foundMapping = _exceptionMapping.find(std::type_index(typeid(exception)));

    HTTPResponse response = foundMapping != _exceptionMapping.end() ? foundMapping->second : _fallback;

    response.body = exception.what();
    return response;
}

ExceptionHandler::ExceptionHandler() {
    _fallback.statusMessage = "Internal Server Error";
    _fallback.statusCode = "500";

    addException(std::type_index(typeid(method_not_allowed_exception)), "405", "Method Not Allowed");
    addException(std::type_index(typeid(parse_failure_exception)), "400", "Bad Request");
    addException(std::type_index(typeid(endpoint_not_found_exception)), "404", "Not Found");
}