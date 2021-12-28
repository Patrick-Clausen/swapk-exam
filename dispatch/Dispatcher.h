//
// Created by einar on 12/17/21.
//

#ifndef SWAPK_EXAM_DISPATCHER_H
#define SWAPK_EXAM_DISPATCHER_H

#include <string>
#include <map>
#include <functional>
#include "../http/HTTPRequest.h"
#include "../http/HTTPResponse.h"

#include "../meta/hasPath.h"
#include "../meta/hasGet.h"
#include "../meta/hasPost.h"
#include "../meta/hasPut.h"
#include "../meta/hasDelete.h"
#include "../meta/detect.h"

namespace restbuilder::dispatch {
    class Dispatcher {
    public:
        template<typename T>
        void registerController(T ctl) {
            validateControllers<T>();
            auto path = T::Path();

            if constexpr (meta::detect<meta::hasGet, T, std::string(T::*)(std::string)>::value) {
                _ctl.insert(
                        std::make_pair(path,
                                       std::unordered_map<std::string, std::function<std::string(std::string)>>()));
                _ctl[path].insert(std::make_pair(std::string("GET"), std::bind(&T::GET, &ctl, std::placeholders::_1)));
            }

            if constexpr (meta::detect<meta::hasPost, T, std::string(T::*)(std::string)>::value) {
                _ctl.insert(
                        std::make_pair(path,
                                       std::unordered_map<std::string, std::function<std::string(std::string)>>()));
                _ctl[path].insert(std::make_pair("POST", std::bind(&T::POST, &ctl, std::placeholders::_1)));
            }

            if constexpr (meta::detect<meta::hasDelete, T, std::string(T::*)(std::string)>::value) {
                _ctl.insert(
                        std::make_pair(path,
                                       std::unordered_map<std::string, std::function<std::string(std::string)>>()));
                _ctl[path].insert(std::make_pair("DELETE", std::bind(&T::DELETE, &ctl, std::placeholders::_1)));
            }

            if constexpr (meta::detect<meta::hasPut, T, std::string(T::*)(std::string)>::value) {
                _ctl.insert(
                        std::make_pair(path,
                                       std::unordered_map<std::string, std::function<std::string(std::string)>>()));
                _ctl[path].insert(std::make_pair("PUT", std::bind(&T::PUT, &ctl, std::placeholders::_1)));
            }

        };

        template<typename T>
        static constexpr void validateControllers() {
            static_assert(meta::hasPath<T>::value || T::Path() != "" || T::Path().find('/', 0),
                          "Controller has no path it should be defined like this: [[nodiscard]] static constexpr std::string_view Path() {return ""path"";}");
            static_assert(meta::detect<meta::hasGet, T, std::string(T::*)(std::string)>::value ||
                          meta::detect<meta::hasPost, T, std::string(T::*)(std::string)>::value ||
                          meta::detect<meta::hasDelete, T, std::string(T::*)(std::string)>::value ||
                          meta::detect<meta::hasPut, T, std::string(T::*)(std::string)>::value,
                          "Controller has no valid methods");
        };

        http::HTTPResponse dispatch(http::HTTPRequest&& request);

    private:
        std::unordered_map<std::string_view, std::unordered_map<std::string, std::function<std::string(
                std::string)>>> _ctl;
    };
}

#endif //SWAPK_EXAM_DISPATCHER_H
