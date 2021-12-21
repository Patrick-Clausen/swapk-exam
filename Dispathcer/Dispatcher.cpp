//
// Created by einar on 12/17/21.
//

#include <iostream>
#include "Dispatcher.h"
#include "hasPath.h"
#include "hasGet.h"
#include "hasPost.h"
#include "hasPut.h"
#include "hasDelete.h"


void Dispatcher::dispatch(std::string_view path, const std::string &method) {
    auto ctlItt = _ctl.find(path);
    if (ctlItt != _ctl.end()) {
        auto methodPair = ctlItt->second.find(method);
        if (methodPair != ctlItt->second.end()) {
            methodPair->second("Test");
        }
    }
}
