//
// Created by einar on 12/17/21.
//

#ifndef SWAPK_EXAM_HASGET_H
#define SWAPK_EXAM_HASGET_H

#include <type_traits>

namespace restbuilder::meta {
    template<typename T, typename U>
    using hasGet = decltype(static_cast<U>(&T::GET));
}

#endif //SWAPK_EXAM_HASGET_H

