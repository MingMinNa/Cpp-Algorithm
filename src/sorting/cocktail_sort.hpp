#ifndef ALGO_COCKTAIL_SORT
#define ALGO_COCKTAIL_SORT

#include "../algo_utils.hpp"
#include <concepts>
#include <functional>

namespace algo_imp::sorting {

template <HasCompareOps T, typename Compare = std::less<T>>
void cocktail_sort(T* arr, size_t n, Compare cmp = Compare{});

}

#include "cocktail_sort.tpp"

#endif