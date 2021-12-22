//
// Created by Tue on 20/12/2021.
//

#include "ExceptionHandling.h"

void ExceptionHandling::AddException(const std::exception& exception, std::string_view statusCode, std::string_view statusMessage) {
    HTTPResponse response;
    response.statusCode = statusCode;
    response.protocolVersion = ProtocolVersion::HTTP_1_1;
    response.statusMessage = statusMessage;
    exceptionMapping.insert({typeid(exception).name(), response});
}

HTTPResponse ExceptionHandling::HandleException(const std::exception& exception) {
    HTTPResponse response = exceptionMapping.find(typeid(exception).name())->second;
    response.body = exception.what();
    return response;
}

ExceptionHandling::ExceptionHandling() {
    AddException(std::bad_alloc(), "500", "Internal error - bad alloc");
}
