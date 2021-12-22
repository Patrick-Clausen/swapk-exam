//
// Created by einar on 12/21/21.
//

#ifndef SWAPK_EXAM_DETECT_H
#define SWAPK_EXAM_DETECT_H

#include <type_traits>

template<typename...>
using void_t = void;

template<typename AlwaysVoid, template<typename...> class Operation, typename... Args>
struct detect_impl : std::false_type {
};

template<template<typename...> class Operation, typename... Args>
struct detect_impl<void_t<Operation<Args...>>, Operation, Args...> : std::true_type {
};

template<template<typename...> class Operation, typename... Args>
using detect = detect_impl<void_t<>, Operation, Args...>;
#endif //SWAPK_EXAM_DETECT_H
