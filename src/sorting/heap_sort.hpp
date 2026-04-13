#ifndef ALGO_HEAP_SORT
#define ALGO_HEAP_SORT

#include "../algo_utils.hpp"
#include <concepts>
#include <functional>

namespace algo_imp::sorting {

template <HasCompareOps T, typename Compare = std::less<T>>
void heap_sort(T* arr, size_t n, Compare cmp = Compare{});

template <HasCompareOps T, typename Compare = std::less<T>>
void heapify(T* arr, size_t n, size_t curr_index, Compare cmp = Compare{});

template <HasCompareOps T, typename Compare = std::less<T>>
void build_heap(T* arr, size_t n, Compare cmp = Compare{});

}

#include "heap_sort.tpp"

#endif