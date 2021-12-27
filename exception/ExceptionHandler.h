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

namespace restbuilder::exception {
    class ExceptionHandler {
    public:
        ExceptionHandler();

        void addException(const std::type_index &type, std::string_view statusCode, std::string_view statusMessage);

        http::HTTPResponse handleException(std::exception &&exception);

    private:
        std::unordered_map<std::type_index, http::HTTPResponse> _exceptionMapping;
        http::HTTPResponse _fallback;
    };
}

#endif //SWAPK_EXAM_EXCEPTIONHANDLER_H
