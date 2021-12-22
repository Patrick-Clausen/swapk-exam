//
// Created by Patrick Clausen on 20/12/2021.
//

#ifndef SWAPK_EXAM_DISPATCHER_H
#define SWAPK_EXAM_DISPATCHER_H

#include <iostream>

#include "../http/HTTPRequest.h"
#include "../http/HTTPResponse.h"

#include "../exception/defaults/method_not_allowed_exception.h"
#include "../exception/defaults/parse_failure_exception.h"
#include "../exception/defaults/endpoint_not_found_exception.h"

class Dispatcher {
public:
    static HTTPResponse dispatch(HTTPRequest request) {
        std::cout << "REQUEST RECEIVED" << std::endl;
        std::cout << "PROTOCOL VERSION: " << request.protocolVersion << std::endl;
        std::cout << "METHOD: " << request.method << std::endl;
        std::cout << "PATH: " << request.path << std::endl;
        for (auto header : request.headers) {
            std::cout << "HEADER: " << header.first << " - " << header.second << std::endl;
        }
        std::cout << "CONTENT: " << request.body << std::endl;

        if (request.path == "/not-supported" && request.method == RequestMethod::GET) {
            throw method_not_allowed_exception("not-supported", RequestMethod::GET);
        }
        if (request.path == "/not-found") {
            throw endpoint_not_found_exception("/not-found");
        }
        if (request.path == "/parse-failure") {
            throw parse_failure_exception();
        }

        HTTPResponse response;
        response.protocolVersion = request.protocolVersion;
        response.statusCode = "200";
        response.statusMessage = "OK";
        response.body = "HEJ TUE!!!!!!11!!!!";

        return response;
    }
};

#endif //SWAPK_EXAM_DISPATCHER_H
