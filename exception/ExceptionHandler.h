//
// Created by Tue on 20/12/2021.
//

#ifndef SWAPK_EXAM_EXCEPTIONHANDLER_H
#define SWAPK_EXAM_EXCEPTIONHANDLER_H

#include <map>
#include <exception>
#include <string>
#include <typeindex>
#include "../http/HTTPResponse.h"


class ExceptionHandler {
public:
    ExceptionHandler();

    void addException(const std::type_index& type, std::string_view statusCode, std::string_view statusMessage);
    HTTPResponse handleException(const std::exception& exception);

private:
    std::unordered_map<std::type_index, HTTPResponse> _exceptionMapping;
    HTTPResponse _fallback;
};

#endif //SWAPK_EXAM_EXCEPTIONHANDLER_H
