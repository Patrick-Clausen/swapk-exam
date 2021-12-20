//
// Created by Tue on 17/12/2021.
//

#ifndef SWAPK_EXAM_HTTPREQUEST_H
#define SWAPK_EXAM_HTTPREQUEST_H

#include <string>
#include "HTTPCall.h"
#include "HTTPEnums.h"

struct HTTPRequest : public HTTPCall {
    std::string path;
    RequestMethod method;
};

#endif //SWAPK_EXAM_HTTPREQUEST_H
