//
// Created by Tue on 20/12/2021.
//

#include "ExeptionHandling.h"

void ExceptionHandling::AddException(const std::exception& exception, std::string_view statusCode, std::string_view statusMessage) {
    HttpResponse response;
    response.statusCode = statusCode;
    response.protocolVersion = "Http/1.1";
    response.statusMessage = statusMessage;
    exceptionMapping.insert({typeid(exception).name(), response});
}

HttpResponse ExceptionHandling::HandleException(const std::exception& exception) {
    HttpResponse response = exceptionMapping.find(typeid(exception).name())->second;
    response.body = exception.what();
    return response;
}

ExceptionHandling::ExceptionHandling() {
    AddException(std::bad_alloc(), "500", "Internal error - bad alloc");
}
