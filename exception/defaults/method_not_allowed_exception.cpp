//
// Created by Patrick Clausen on 22/12/2021.
//

#include "method_not_allowed_exception.h"

method_not_allowed_exception::method_not_allowed_exception(const std::string &endpoint,
                                                           const RequestMethod attemptedMethod)
        : std::runtime_error("Tried to access endpoint " + endpoint + " with non-supported method %s" + getStringFromEnumValue(attemptedMethod)) {}

method_not_allowed_exception::method_not_allowed_exception()
        : std::runtime_error("Tried to access endpoint with non-supported method") {}
