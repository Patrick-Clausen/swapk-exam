//
// Created by Patrick Clausen on 23/12/2021.
//

#ifndef SWAPK_EXAM_HASINTERCEPT_H
#define SWAPK_EXAM_HASINTERCEPT_H

#include <type_traits>

namespace restbuilder::meta {
    template<typename T, typename U>
    using hasIntercept = decltype(static_cast<U>(&T::intercept));
}

#endif //SWAPK_EXAM_HASINTERCEPT_H
