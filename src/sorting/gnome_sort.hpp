#ifndef ALGO_GNOME_SORT
#define ALGO_GNOME_SORT

#include "../algo_utils.hpp"
#include <concepts>
#include <functional>

namespace algo_imp::sorting {

template <HasCompareOps T, typename Compare = std::less<T>>
void gnome_sort(T* arr, size_t n, Compare cmp = Compare{});

}

#include "gnome_sort.tpp"

#endif