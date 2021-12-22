//
// Created by Patrick Clausen on 20/12/2021.
//

#include "HTTPEnums.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

const std::map<ProtocolVersion, std::string> protocolVersionEnumAsString = map_list_of
        (HTTP_1_0, "HTTP/1.0")
        (HTTP_1_1, "HTTP/1.1")
        (HTTP_2, "HTTP/2");

template<>
std::string getStringFromEnumValue<ProtocolVersion>(ProtocolVersion protocolVersion) {
    return protocolVersionEnumAsString.at(protocolVersion);
}
template<>
ProtocolVersion getEnumValueFromString<ProtocolVersion>(std::string& str) {
    for (const auto& protocol : protocolVersionEnumAsString) {
        if (protocol.second == str) {
            return protocol.first;
        }
    }
    throw std::out_of_range("No matching ProtocolVersion for supplied string");
}

const std::map<RequestMethod, std::string> requestMethodEnumAsString = map_list_of
        (GET, "GET")
        (HEAD, "HEAD")
        (POST, "POST")
        (PUT, "PUT")
        (DELETE, "DELETE")
        (CONNECT, "CONNECT")
        (OPTIONS, "OPTIONS")
        (TRACE, "TRACE")
        (PATCH, "PATCH");

template<>
std::string getStringFromEnumValue<RequestMethod>(RequestMethod requestMethod) {
    return requestMethodEnumAsString.at(requestMethod);
}

template<>
RequestMethod getEnumValueFromString<RequestMethod>(std::string& str) {
    for (const auto& requestMethod : requestMethodEnumAsString) {
        if (requestMethod.second == str) {
            return requestMethod.first;
        }
    }
    throw std::out_of_range("No matching RequestMethod for supplied string");
}
