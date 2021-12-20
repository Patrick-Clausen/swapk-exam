//
// Created by Tue on 17/12/2021.
//
//https://developer.mozilla.org/en-US/docs/Web/HTTP/Overview
#ifndef SWAPK_EXAM_HTTPCALL_H
#define SWAPK_EXAM_HTTPCALL_H
#include <map>
typedef std::map<std::string,std::string> Headers;

class HttpCall {
public:
    Headers headers;
    std::string body;
};


#endif //SWAPK_EXAM_HTTPCALL_H
