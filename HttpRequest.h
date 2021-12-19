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

    friend std::ostream &operator<<( std::ostream &output, const HttpRequest &httpRequest ) {
        output << httpRequest.method << " " << httpRequest.path << " " << httpRequest.protocolVersion << std::endl;

        for (auto it = httpRequest.headers.begin(); it != httpRequest.headers.end(); it++)
        {
            output << it->first << ": " << it->second << std::endl;
        }

        output << httpRequest.body;

        return output;
    }
};

#endif //SWAPK_EXAM_HTTPREQUEST_H
