//
// Created by Patrick Clausen on 22/12/2021.
//

#include "endpoint_not_found_exception.h"

using namespace restbuilder::exception::defaults;

endpoint_not_found_exception::endpoint_not_found_exception()
        : std::runtime_error("Tried to access endpoint that could not be found") {

}

endpoint_not_found_exception::endpoint_not_found_exception(const std::string &endpoint)
        : std::runtime_error("Tried to access endpoint " + endpoint + " which could not be found") {

}
