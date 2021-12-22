//
// Created by einar on 12/17/21.
//

#ifndef SWAPK_EXAM_HASPUT_H
#define SWAPK_EXAM_HASPUT_H

#include <type_traits>

template<typename T, typename U>
using hasPut = decltype(static_cast<U>(&T::PUT));
#endif //SWAPK_EXAM_HASPUT_H
