//
// Created by einar on 12/17/21.
//

#include "Dispatcher.h"

#include "../exception/defaults/endpoint_not_found_exception.h"
#include "../exception/defaults/method_not_allowed_exception.h"
#include "../http/HTTPEnums.h"

using namespace restbuilder::dispatch;

restbuilder::http::HTTPResponse Dispatcher::dispatch(http::HTTPRequest&& request) {
    auto ctlItt = _ctl.find(request.path);
    if (ctlItt != _ctl.end()) {
        auto methodPair = ctlItt->second.find(getStringFromEnumValue(request.method));
        if (methodPair != ctlItt->second.end()) {
            return http::HTTPResponse(methodPair->second(request.body));
        }
        throw exception::defaults::method_not_allowed_exception(request.path, request.method);
    }
    throw exception::defaults::endpoint_not_found_exception(request.path);
}
