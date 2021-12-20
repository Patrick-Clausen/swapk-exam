//
// Created by Tue on 20/12/2021.
//

#ifndef SWAPK_EXAM_EXEPTIONHANDLING_H
#define SWAPK_EXAM_EXEPTIONHANDLING_H

#include <exception>
#include <string>
#include "../HttpTypes/HttpResponse.h"

class ExceptionHandling {
public:
    void AddException(const std::exception& exception, std::string_view statusCode, std::string_view statusMessage);
    HttpResponse HandleException(const std::exception& exception);
    ExceptionHandling();
private:
    std::map<const char*, HttpResponse> exceptionMapping;
};


#endif //SWAPK_EXAM_EXEPTIONHANDLING_H
