#ifndef ALGO_BUCKET_SORT
#define ALGO_BUCKET_SORT

#include "../algo_utils.hpp"
#include <concepts>
#include <functional>

namespace algo_imp::sorting {

const size_t MAX_NUM_BUCKETS = 1000ull;

template <Numeric T, typename Compare = std::less<T>>
void bucket_sort(T* arr, size_t n, size_t num_buckets = 0, Compare cmp = Compare{});

}

#include "bucket_sort.tpp"

#endif