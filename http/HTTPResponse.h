//
// Created by Tue on 17/12/2021.
//

#ifndef SWAPK_EXAM_HTTPRESPONSE_H
#define SWAPK_EXAM_HTTPRESPONSE_H
#include <string>
#include "HTTPCall.h"

struct HTTPResponse : public HTTPCall {
    std::string statusMessage;
    std::string statusCode;
};

#endif //SWAPK_EXAM_HTTPRESPONSE_H
