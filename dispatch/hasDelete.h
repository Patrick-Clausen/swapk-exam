//
// Created by einar on 12/17/21.
//

#ifndef SWAPK_EXAM_HASDELETE_H
#define SWAPK_EXAM_HASDELETE_H

#include <type_traits>

template<typename T, typename U>
using hasDelete = decltype(static_cast<U>(&T::DELETE));
#endif //SWAPK_EXAM_HASDELETE_H
