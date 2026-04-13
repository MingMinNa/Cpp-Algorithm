#ifndef ALGO_COUNTING_SORT
#define ALGO_COUNTING_SORT

#include "../algo_utils.hpp"
#include <concepts>
#include <functional>

namespace algo_imp::sorting {

template <std::integral T, typename Compare = std::less<T>>
void counting_sort(T* arr, size_t n, Compare cmp = Compare{});

}

#include "counting_sort.tpp"

#endif