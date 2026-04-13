#ifndef ALGO_INSERTION_SORT
#define ALGO_INSERTION_SORT

#include "../algo_utils.hpp"
#include <concepts>
#include <functional>

namespace algo_imp::sorting {

template <HasCompareOps T, typename Compare = std::less<T>>
void insertion_sort(T* arr, size_t n, Compare cmp = Compare{});

}

#include "insertion_sort.tpp"

#endif