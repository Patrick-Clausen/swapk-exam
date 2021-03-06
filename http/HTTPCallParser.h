//
// Created by Tue on 17/12/2021.
//

#ifndef SWAPK_EXAM_HTTPCALLPARSER_H
#define SWAPK_EXAM_HTTPCALLPARSER_H

#include "HTTPRequest.h"
#include "HTTPResponse.h"
#include <queue>
#include <string>

namespace restbuilder::http {
    class HTTPCallParser {
    public:
        static HTTPRequest parseRequest(const std::string &httpRequestString);

        static std::string stringifyResponse(const HTTPResponse &httpResponse);

    private:
        static void parseAndAddStatus(std::string &&statusLine, HTTPRequest &httpRequest);

        static void parseAndAddHeader(std::string &&headerString, HTTPRequest &httpRequest);

        static std::queue<std::string> splitStringByNewLine(std::string stringToSplit);

        static std::string stringifyStatusLine(const HTTPResponse &httpResponse);

        static void throwParseExceptionIfTrue(bool condition, std::string &&reason);
    };

}


#endif //SWAPK_EXAM_HTTPCALLPARSER_H
