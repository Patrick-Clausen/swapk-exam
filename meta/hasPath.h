//
// Created by einar on 12/19/21.
//

#ifndef SWAPK_EXAM_HASPATH_H
#define SWAPK_EXAM_HASPATH_H

#include <type_traits>
#include <boost/static_assert.hpp>

namespace restbuilder::meta {
    template<typename T, typename = void>
    struct hasPath : std::false_type {
    };

    template<typename T>
    struct hasPath<T, std::void_t<decltype(T::Path())>> : std::true_type {
    };
}

#endif //SWAPK_EXAM_HASPATH_H
