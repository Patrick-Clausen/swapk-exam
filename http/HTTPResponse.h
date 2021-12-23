//
// Created by Tue on 17/12/2021.
//

#ifndef SWAPK_EXAM_HTTPRESPONSE_H
#define SWAPK_EXAM_HTTPRESPONSE_H
#include <string>
#include <utility>
#include "HTTPCall.h"

struct HTTPResponse : public HTTPCall {
    explicit HTTPResponse(std::string responseBody) {
        statusCode = "200";
        statusMessage = "OK";
        protocolVersion = ProtocolVersion::HTTP_1_1;
        body = std::move(responseBody);
    }

    std::string statusMessage;
    std::string statusCode;
};

#endif //SWAPK_EXAM_HTTPRESPONSE_H
