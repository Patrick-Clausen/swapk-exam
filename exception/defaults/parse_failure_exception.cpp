//
// Created by Patrick Clausen on 22/12/2021.
//

#include "parse_failure_exception.h"

using namespace restbuilder::exception::defaults;

parse_failure_exception::parse_failure_exception()
        : std::runtime_error("Could not parse HTTP request") {

}

parse_failure_exception::parse_failure_exception(std::string &&reason)
        : std::runtime_error("Could not parse HTTP request. Reason: " + reason) {

}
