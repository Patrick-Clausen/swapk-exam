//
// Created by einar on 12/17/21.
//

#include "Dispatcher.h"

#include "../exception/defaults/endpoint_not_found_exception.h"
#include "../exception/defaults/method_not_allowed_exception.h"
#include "../http/HTTPEnums.h"

HTTPResponse Dispatcher::dispatch(HTTPRequest request) {
    auto ctlItt = _ctl.find(request.path);
    if (ctlItt != _ctl.end()) {
        auto methodPair = ctlItt->second.find(getStringFromEnumValue(request.method));
        if (methodPair != ctlItt->second.end()) {
            // TODO: More error handling
            HTTPResponse response;
            response.statusCode = "200";
            response.statusMessage = "OK";
            response.protocolVersion = ProtocolVersion::HTTP_1_1;
            response.body = methodPair->second(request.body);
            return response;
        }
        throw method_not_allowed_exception(request.path, request.method);
    }
    throw endpoint_not_found_exception(request.path);
}
