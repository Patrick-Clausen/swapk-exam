//
// Created by Patrick Clausen on 20/12/2021.
//

#include "HTTPCallParser.h"

#include "HTTPEnums.h"
#include <sstream>
#include <algorithm>

// TODO: handle parsing errors

HTTPRequest HTTPCallParser::parseRequest(const std::string &httpRequestString) {
    HTTPRequest httpRequest;
    auto strings = splitStringByNewLine(httpRequestString);

    std::string statusLine = strings.front();
    strings.pop();
    parseAndAddStatus(statusLine, httpRequest);

    while(!strings.front().empty()){
        parseAndAddHeader(strings.front(), httpRequest);
        strings.pop();
    }
    strings.pop();

    httpRequest.body = strings.front();

    return httpRequest;
}

std::string HTTPCallParser::stringifyResponse(const HTTPResponse &httpResponse) {
    std::string delimiter = "\r\n";
    std::stringstream builder;

    builder << stringifyStatusline(httpResponse) << delimiter;

    std::for_each(httpResponse.headers.begin(), httpResponse.headers.end(), [&builder, &delimiter](std::pair<std::string, std::string>&& header) {
        builder << header.first << ": " << header.second << delimiter;
    });

    builder << delimiter << httpResponse.body << delimiter;

    return builder.str();
}

void HTTPCallParser::parseAndAddHeader(const std::string& headerString, HTTPRequest &httpRequest) {
    size_t i = headerString.find(": ");
    std::string key = headerString.substr(0, i);
    std::string value = headerString.substr(i+2, std::string::npos);
}

std::queue<std::string> HTTPCallParser::splitStringByNewLine(std::string stringToSplit) {
    const std::string delimiter = "\r\n";
    std::queue<std::string> lines;

    while (!stringToSplit.empty()) {
        size_t i = stringToSplit.find(delimiter);

        std::string line = stringToSplit.substr(0, i);

        lines.push(line);

        i += 2;
        stringToSplit = stringToSplit.substr(i, std::string::npos);

        if (line.empty()) {
            lines.push(stringToSplit);
            stringToSplit = "";
        }
    }

    return lines;
}

void HTTPCallParser::parseAndAddStatus(const std::string& statusLine, HTTPRequest &httpRequest) {
    char delimiter = ' ';
    std::string substr;
    std::string tmp;
    std::stringstream stream;
    stream << statusLine;

    // METHOD
    std::getline(stream, tmp, delimiter);
    httpRequest.method = getEnumValueFromString<RequestMethod>(tmp);

    // PATH
    std::getline(stream, httpRequest.path, delimiter);

    // PROTOCOL VERSION
    std::getline(stream, tmp, delimiter);
    httpRequest.protocolVersion = getEnumValueFromString<ProtocolVersion>(tmp);
}

std::string HTTPCallParser::stringifyStatusline(const HTTPResponse &httpResponse) {
    char delimiter = ' ';
    std::stringstream builder;
    builder << getStringFromEnumValue(httpResponse.protocolVersion) << delimiter << httpResponse.statusCode << delimiter << httpResponse.statusMessage;
    return builder.str();
}