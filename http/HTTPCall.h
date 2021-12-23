//
// Created by Tue on 17/12/2021.
//
//https://developer.mozilla.org/en-US/docs/Web/HTTP/Overview
#ifndef SWAPK_EXAM_HTTPCALL_H
#define SWAPK_EXAM_HTTPCALL_H

#include <unordered_map>
#include "HTTPEnums.h"


typedef std::unordered_multimap<std::string,std::string> Headers;

class HTTPCall {
public:
    ProtocolVersion protocolVersion;
    Headers headers;
    std::string body;
};

#endif //SWAPK_EXAM_HTTPCALL_H
