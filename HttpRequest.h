//
// Created by Tue on 17/12/2021.
//

#ifndef SWAPK_EXAM_HTTPREQUEST_H
#define SWAPK_EXAM_HTTPREQUEST_H
#include <string>
#include <map>
#include "HttpCall.h"

struct HttpRequest : public HttpCall {
    std::string path;
    std::string method;
    std::string protocolVersion;
};

#endif //SWAPK_EXAM_HTTPREQUEST_H
