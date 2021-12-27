//
// Created by Patrick Clausen on 22/12/2021.
//

#include "method_not_allowed_exception.h"

using namespace restbuilder::exception::defaults;

method_not_allowed_exception::method_not_allowed_exception(const std::string &endpoint,
                                                           const http::enums::RequestMethod attemptedMethod)
        : std::runtime_error("Tried to access endpoint " + endpoint + " with non-supported method " + getStringFromEnumValue(attemptedMethod)) {}

method_not_allowed_exception::method_not_allowed_exception()
        : std::runtime_error("Tried to access endpoint with non-supported method") {}
