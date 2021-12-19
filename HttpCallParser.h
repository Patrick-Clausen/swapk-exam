//
// Created by Tue on 17/12/2021.
//

#ifndef SWAPK_EXAM_HTTPCALLPARSER_H
#define SWAPK_EXAM_HTTPCALLPARSER_H

#include <sstream>
#include <queue>
#include <iostream>
#include <utility>
#include "HttpCall.h"
#include "HttpRequest.h"
#include "HttpResponse.h"

class HttpCallParser {
public:
    HttpRequest ParseCallToRequest(const std::string& httpRequestString);
    HttpResponse ParseCallToResponse(const std::string& httpResponseString);

private:
    void AddHeadersAndBody(std::queue<std::string> &httpCallStringArray, HttpCall &httpCall);
    std::queue<std::string> SplitStringByNewLine(const std::string& stringToSplit);
};

HttpRequest HttpCallParser::ParseCallToRequest(const std::string& httpRequestString) {
    HttpRequest httpRequest;
    auto strings = SplitStringByNewLine(httpRequestString);

    std::string firstLine = strings.front();
    std::string::size_type charPositionMethod = firstLine.find(' ');
    httpRequest.method = firstLine.substr(0, charPositionMethod);
    std::string::size_type charPositionPath = firstLine.find(' ', charPositionMethod+1);
    httpRequest.path = firstLine.substr(charPositionMethod+1, charPositionPath-charPositionMethod);
    std::string::size_type charPositionProtocolVersion = firstLine.find(' ', charPositionPath+1);
    httpRequest.protocolVersion = firstLine.substr(charPositionPath+1, charPositionProtocolVersion-charPositionPath);
    strings.pop();

    AddHeadersAndBody(strings,httpRequest);

    return httpRequest;
}

HttpResponse HttpCallParser::ParseCallToResponse(const std::string& httpResponseString) {
    HttpResponse httpResponse;
    auto strings = SplitStringByNewLine(httpResponseString);

    std::string firstLine = strings.front();
    std::string::size_type charPositionMethod = firstLine.find(' ');
    httpResponse.protocolVersion = firstLine.substr(0, charPositionMethod);
    std::string::size_type charPositionPath = firstLine.find(' ', charPositionMethod+1);
    httpResponse.statusCode = firstLine.substr(charPositionMethod+1, charPositionPath-charPositionMethod-1);
    std::string::size_type charPositionProtocolVersion = firstLine.find(' ', charPositionPath+1);
    httpResponse.statusMessage = firstLine.substr(charPositionPath+1, charPositionProtocolVersion-charPositionPath-1);
    strings.pop();

    AddHeadersAndBody(strings,httpResponse);

    return httpResponse;
}

void HttpCallParser::AddHeadersAndBody(std::queue<std::string> &httpCallStringArray, HttpCall &httpCall) {
    Headers headers;
    std::string tempString;
    while(!httpCallStringArray.empty())
    {
        if(httpCallStringArray.front().empty())
        {
            httpCallStringArray.pop();
            httpCall.body = httpCallStringArray.front();
            httpCallStringArray.pop();
            while(!httpCallStringArray.empty()) {
                httpCall.body = httpCall.body.append(" ");
                httpCall.body = httpCall.body.append(httpCallStringArray.front());
                httpCallStringArray.pop();
            }
            break;
        }
        tempString = httpCallStringArray.front();
        std::string::size_type charPosition = tempString.find(' ');
        std::string key = tempString.substr(0, charPosition-1);
        std::string value = tempString.substr(charPosition+1, tempString.back());
        headers.insert({key, value});
        httpCallStringArray.pop();
    }
    httpCall.headers = headers;
}

std::queue<std::string> HttpCallParser::SplitStringByNewLine(const std::string& stringToSplit) {
    std::stringstream ss(stringToSplit);
    std::string tempString;
    std::queue<std::string> strings;

    while(std::getline(ss, tempString))
    {
        strings.push(tempString);
    }
    return strings;
}

#endif //SWAPK_EXAM_HTTPCALLPARSER_H
