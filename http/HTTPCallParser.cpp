//
// Created by Patrick Clausen on 20/12/2021.
//

#include "HTTPCallParser.h"

#include "HTTPEnums.h"
#include "../exception/defaults/parse_failure_exception.h"
#include <sstream>
#include <algorithm>

// TODO: handle parsing errors

HTTPRequest HTTPCallParser::parseRequest(const std::string &httpRequestString) {
    HTTPRequest httpRequest;
    throwParseExceptionIfFalse(httpRequestString.empty(), "Trying to parse request, but string to parse is empty");

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

    builder << stringifyStatusLine(httpResponse) << delimiter;

    std::for_each(httpResponse.headers.begin(), httpResponse.headers.end(), [&builder, &delimiter](std::pair<std::string, std::string>&& header) {
        builder << header.first << ": " << header.second << delimiter;
    });

    builder << delimiter << httpResponse.body << delimiter;

    return builder.str();
}

void HTTPCallParser::parseAndAddHeader(const std::string& headerString, HTTPRequest &httpRequest) {
    size_t i = headerString.find(": ");
    throwParseExceptionIfFalse(i == std::string::npos, "Trying to parse and add header, but no ':' is not found");

    std::string key = headerString.substr(0, i);
    std::string value = headerString.substr(i+2, std::string::npos);
    httpRequest.headers.insert({key, value});
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

std::string HTTPCallParser::stringifyStatusLine(const HTTPResponse &httpResponse) {
    throwParseExceptionIfFalse(
            httpResponse.statusMessage.empty() ||
            httpResponse.statusCode.empty(),
            "Trying to stringify status line but, a value was empty");

    char delimiter = ' ';
    std::stringstream builder;
    builder << getStringFromEnumValue(httpResponse.protocolVersion) << delimiter << httpResponse.statusCode << delimiter << httpResponse.statusMessage;
    return builder.str();
}

void HTTPCallParser::throwParseExceptionIfFalse(bool condition, const std::string& reason) //Maybe rename, men syntes det er mere clean sådan her.
{
    if (condition)
    {
        throw parse_failure_exception(reason);
    }
}