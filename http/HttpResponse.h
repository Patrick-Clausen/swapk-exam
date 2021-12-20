//
// Created by Tue on 17/12/2021.
//

#ifndef SWAPK_EXAM_HTTPRESPONSE_H
#define SWAPK_EXAM_HTTPRESPONSE_H
#include <string>
#include <map>
#include "HttpCall.h"
#include <ostream>

struct HttpResponse : public HttpCall {
    std::string statusMessage;
    std::string statusCode;
    std::string protocolVersion;

    friend std::ostream &operator<<( std::ostream &output, const HttpResponse &httpResponse ) {
        output << httpResponse.protocolVersion << " " << httpResponse.statusCode << " " << httpResponse.statusMessage << "\r\n";

        for (auto it = httpResponse.headers.begin(); it != httpResponse.headers.end(); it++)
        {
            output << it->first << ": " << it->second << "\r\n";
        }

        output << "\r\n" << httpResponse.body;

        return output;
    }
};


#endif //SWAPK_EXAM_HTTPRESPONSE_H
