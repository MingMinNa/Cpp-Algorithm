#ifndef ALGO_RADIX_SORT
#define ALGO_RADIX_SORT

#include "../algo_utils.hpp"
#include <concepts>
#include <functional>

namespace algo_imp::sorting {

const size_t NUM_BUCKETS = 1ull << 8;

template <std::unsigned_integral T, typename Compare = std::less<T>>
void radix_sort(T* arr, size_t n, Compare cmp = Compare{});

}

#include "radix_sort.tpp"

#endif