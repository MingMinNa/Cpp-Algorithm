#ifndef ALGO_QUICK_SORT
#define ALGO_QUICK_SORT

#include "../algo_utils.hpp"
#include <concepts>
#include <functional>

namespace algo_imp::sorting {

constexpr bool RANDOM_PIVOT_DEFAULT = true;

// Note: [start, end)
template <HasCompareOps T, typename Compare = std::less<T>>
void quick_sort(T* arr, size_t start, size_t end, bool random_pivot = RANDOM_PIVOT_DEFAULT, Compare cmp = Compare{});

// Note: [start, end)
template <HasCompareOps T, typename Compare = std::less<T>>
size_t partition(T* arr, size_t start, size_t end, bool random_pivot = RANDOM_PIVOT_DEFAULT, Compare cmp = Compare{});

}

#include "quick_sort.tpp"

#endif