//
// Created by Patrick Clausen on 22/12/2021.
//

#ifndef SWAPK_EXAM_METHOD_NOT_ALLOWED_EXCEPTION_H
#define SWAPK_EXAM_METHOD_NOT_ALLOWED_EXCEPTION_H

#include <stdexcept>
#include "../../http/HTTPEnums.h"

class method_not_allowed_exception : public std::runtime_error {
public:
    method_not_allowed_exception();
    explicit method_not_allowed_exception(const std::string &endpoint, RequestMethod attemptedMethod);
};


#endif //SWAPK_EXAM_METHOD_NOT_ALLOWED_EXCEPTION_H
