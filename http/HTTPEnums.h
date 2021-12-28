//
// Created by Patrick Clausen on 20/12/2021.
//

#ifndef SWAPK_EXAM_HTTPENUMS_H
#define SWAPK_EXAM_HTTPENUMS_H

#include <string>

namespace restbuilder::http::enums {
    enum ProtocolVersion {
        HTTP_1_0,
        HTTP_1_1,
        HTTP_2
    };

    enum RequestMethod {
        GET,
        HEAD,
        POST,
        PUT,
        DELETE,
        CONNECT,
        OPTIONS,
        TRACE,
        PATCH
    };

    template<typename T>
    extern std::string getStringFromEnumValue(T enumValue);

    template<typename T>
    extern T getEnumValueFromString(std::string &str);
}

#endif //SWAPK_EXAM_HTTPENUMS_H
