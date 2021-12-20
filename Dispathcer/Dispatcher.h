//
// Created by einar on 12/17/21.
//

#ifndef SWAPK_EXAM_DISPATCHER_H
#define SWAPK_EXAM_DISPATCHER_H

#include <string>
#include <map>
#include <functional>
#include "hasPath.h"
#include "hasGet.h"
#include "hasPost.h"
#include "hasPut.h"
#include "hasDelete.h"
#include "detect.h"

using namespace std::placeholders;

class Dispatcher {
public:
    template<typename T>
    void registerController(T ctl) {
        validateControllers<T>();
        auto path = T::Path();

        if constexpr (detect<hasGet, T, std::string(T::*)(std::string)>::value) {
            _ctl.insert(
                    std::make_pair(path, std::unordered_map<std::string, std::function<std::string(std::string)>>()));
            _ctl[path].insert(std::make_pair(std::string("GET"), std::bind(&T::GET, &ctl, _1)));
        }

        if constexpr (detect<hasPost, T, std::string(T::*)(std::string)>::value) {
            _ctl.insert(
                    std::make_pair(path, std::unordered_map<std::string, std::function<std::string(std::string)>>()));
            _ctl[path].insert(std::make_pair("POST", std::bind(&T::POST, &ctl, _1)));
        }

        if constexpr (detect<hasDelete, T, std::string(T::*)(std::string)>::value) {
            _ctl.insert(
                    std::make_pair(path, std::unordered_map<std::string, std::function<std::string(std::string)>>()));
            _ctl[path].insert(std::make_pair("DELETE", std::bind(&T::DELETE, &ctl, _1)));
        }

        if constexpr (detect<hasPut, T, std::string(T::*)(std::string)>::value) {
            _ctl.insert(
                    std::make_pair(path, std::unordered_map<std::string, std::function<std::string(std::string)>>()));
            _ctl[path].insert(std::make_pair("PUT", std::bind(&T::PUT, &ctl, _1)));
        }

    };

    template<typename T>
    static constexpr void validateControllers() {
        static_assert(hasPath<T>::value,
                      "Controller has no path it should be defined like this: [[nodiscard]] static constexpr std::string_view Path() {return ""path"";}");
        static_assert(detect<hasGet, T, std::string(T::*)(std::string)>::value ||
                      detect<hasPost, T, std::string(T::*)(std::string)>::value ||
                      detect<hasDelete, T, std::string(T::*)(std::string)>::value ||
                      detect<hasPut, T, std::string(T::*)(std::string)>::value,
                      "Controller has no valid methods");
    };

    void dispatch(std::string_view path, const std::string &method);

private:
    std::unordered_map<std::string_view, std::unordered_map<std::string, std::function<std::string(std::string)>>> _ctl;
};

#endif //SWAPK_EXAM_DISPATCHER_H