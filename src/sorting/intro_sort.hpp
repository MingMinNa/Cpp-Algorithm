#ifndef ALGO_INTRO_SORT
#define ALGO_INTRO_SORT

#include "../algo_utils.hpp"
#include <concepts>
#include <functional>

namespace algo_imp::sorting {

template <HasCompareOps T, typename Compare = std::less<T>>
void intro_sort(T* arr, size_t n, Compare cmp = Compare{});

namespace detail {

template <HasCompareOps T, typename Compare>
void intro_sort_depth(T* arr, size_t start, size_t end, size_t depth, Compare cmp);

}

}

#include "intro_sort.tpp"

#endif