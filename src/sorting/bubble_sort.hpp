#ifndef ALGO_BUBBLE_SORT
#define ALGO_BUBBLE_SORT

#include "../algo_utils.hpp"
#include <concepts>
#include <functional>

namespace algo_imp::sorting {

template <HasCompareOps T, typename Compare = std::less<T>>
void bubble_sort(T* arr, size_t n, Compare cmp = Compare{});

}

#include "bubble_sort.tpp"

#endif