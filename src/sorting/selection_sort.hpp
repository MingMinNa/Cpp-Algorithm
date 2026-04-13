#ifndef ALGO_SELECTION_SORT
#define ALGO_SELECTION_SORT

#include "../algo_utils.hpp"
#include <concepts>
#include <functional>

namespace algo_imp::sorting {

template <HasCompareOps T, typename Compare = std::less<T>>
void selection_sort(T* arr, size_t n, Compare cmp = Compare{});

}

#include "selection_sort.tpp"

#endif