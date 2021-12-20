//
// Created by Patrick Clausen on 20/12/2021.
//

#ifndef SWAPK_EXAM_DISPATCHER_H
#define SWAPK_EXAM_DISPATCHER_H

#include <iostream>

#include "../http/HttpRequest.h"
#include "../http/HttpResponse.h"

class Dispatcher {
public:
    static HttpResponse dispatch(HttpRequest request) {
        std::cout << "REQUEST RECEIVED" << std::endl;
        std::cout << "PROTOCOL VERSION: " << request.protocolVersion << std::endl;
        std::cout << "METHOD: " << request.method << std::endl;
        std::cout << "PATH: " << request.path << std::endl;
        for (auto header : request.headers) {
            std::cout << "HEADER: " << header.first << " - " << header.second << std::endl;
        }
        std::cout << "CONTENT: " << request.body << std::endl;

        HttpResponse response;
        response.protocolVersion = request.protocolVersion;
        response.statusCode = "200";
        response.statusMessage = "OK";
        response.body = "HEJ TUE!!!!!!11!!!!";

        return response;
    }
};

#endif //SWAPK_EXAM_DISPATCHER_H
