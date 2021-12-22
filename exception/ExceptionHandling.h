//
// Created by Tue on 20/12/2021.
//

#ifndef SWAPK_EXAM_EXCEPTIONHANDLING_H
#define SWAPK_EXAM_EXCEPTIONHANDLING_H

#include <exception>
#include <string>
#include "../http/HTTPResponse.h"

class ExceptionHandling {
public:
    void AddException(const std::exception& exception, std::string_view statusCode, std::string_view statusMessage);
    HTTPResponse HandleException(const std::exception& exception);
    ExceptionHandling();
private:
    std::map<const char*, HTTPResponse> exceptionMapping;
};


#endif //SWAPK_EXAM_EXCEPTIONHANDLING_H
