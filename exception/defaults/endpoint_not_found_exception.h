//
// Created by Patrick Clausen on 22/12/2021.
//

#ifndef SWAPK_EXAM_ENDPOINT_NOT_FOUND_EXCEPTION_H
#define SWAPK_EXAM_ENDPOINT_NOT_FOUND_EXCEPTION_H

#include <stdexcept>

class endpoint_not_found_exception : public std::runtime_error {
public:
    endpoint_not_found_exception();

    explicit endpoint_not_found_exception(const std::string& endpoint);
};


#endif //SWAPK_EXAM_ENDPOINT_NOT_FOUND_EXCEPTION_H
