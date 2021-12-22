//
// Created by Patrick Clausen on 22/12/2021.
//

#ifndef SWAPK_EXAM_PARSE_FAILURE_EXCEPTION_H
#define SWAPK_EXAM_PARSE_FAILURE_EXCEPTION_H

#include <stdexcept>

class parse_failure_exception : public std::runtime_error {
public:
    parse_failure_exception();
    explicit parse_failure_exception(const std::string& reason);
};


#endif //SWAPK_EXAM_PARSE_FAILURE_EXCEPTION_H
