#ifndef ALGO_BINARY_SEARCH
#define ALGO_BINARY_SEARCH

#include "../algo_utils.hpp"

namespace algo_imp::searching {

namespace detail {

template <HasCompareOps T, typename Compare>
int64_t bound_subroutine(T* arr, size_t n, T target, Compare cmp);

}

// Note: assume the array is ascending sorted.

// If target is in the array, return its index; otherwise, return -1;
template <HasCompareOps T>
int64_t binary_search(T* arr, size_t n, T target);

// Return the first index which arr[index] >= target. 
// If target is greater than all elements, return n; (If n == 0, return -1)
template <HasCompareOps T>
int64_t lower_bound(T* arr, size_t n, T target);

// Return the first index which arr[index] > target. 
// If target is greater than all elements, return n; (If n == 0, return -1)
template <HasCompareOps T>
int64_t upper_bound(T* arr, size_t n, T target);

// Assume arr[0] < arr[1] < ... < arr[i] > arr[i + 1] > arr[i + 2] > ... > arr[n - 1].
template <HasCompareOps T>
int64_t bitonic_search(T* arr, size_t n, T target);

}

#include "binary_search.tpp"

#endif 