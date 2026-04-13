#ifndef ALGO_BUCKET_SORT
#define ALGO_BUCKET_SORT

#include "../algo_utils.hpp"
#include <concepts>
#include <functional>

namespace algo_imp::sorting {

template <HasCompareOps T, typename Compare = std::less<T>>
void bucket_sort(T* arr, size_t n, Compare cmp = Compare{});

}

#include "bucket_sort.tpp"

#endif