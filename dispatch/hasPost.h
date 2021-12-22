//
// Created by einar on 12/17/21.
//
#ifndef SWAPK_EXAM_HASPOST_H
#define SWAPK_EXAM_HASPOST_H

#include <type_traits>

template<typename T, typename U>
using hasPost = decltype(static_cast<U>(&T::POST));
#endif //SWAPK_EXAM_HASPOST_H
