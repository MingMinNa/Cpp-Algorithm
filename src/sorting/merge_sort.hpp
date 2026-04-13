#ifndef ALGO_MERGE_SORT
#define ALGO_MERGE_SORT

#include "../algo_utils.hpp"
#include <concepts>
#include <functional>

namespace algo_imp::sorting {

// Note: [start, end)
template <HasCompareOps T, typename Compare = std::less<T>>
void merge_sort(T* arr, size_t start, size_t end, Compare cmp = Compare{});

// Note: [start, mid), [mid, end)
template <HasCompareOps T, typename Compare = std::less<T>>
void merge(T* arr, size_t start, size_t mid, size_t end, Compare cmp = Compare{});

}

#include "merge_sort.tpp"

#endif