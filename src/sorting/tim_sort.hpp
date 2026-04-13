#ifndef ALGO_TIM_SORT
#define ALGO_TIM_SORT

#include "../algo_utils.hpp"
#include <concepts>
#include <functional>

namespace algo_imp::sorting {

template <HasCompareOps T, typename Compare = std::less<T>>
void tim_sort(T* arr, size_t n, Compare cmp = Compare{});

namespace detail {

// to reduce complexity, the min_gallop is hardcoded (not dynamically adjust).
constexpr uint8_t MIN_MERGE = 64u;
constexpr uint8_t MIN_GALLOP = 7u;

size_t calc_min_run(size_t n);

template <HasCompareOps T, typename Compare> 
size_t get_run(T* arr, const size_t n, size_t run_start, Compare cmp);

template <HasCompareOps T, typename Compare>
void tim_merge(T* arr, size_t start, size_t mid, size_t end, Compare cmp);

template <HasCompareOps T, typename Compare>
ptrdiff_t merge_lo_left(T* arr, std::vector<T> &left, ptrdiff_t start, ptrdiff_t mid, ptrdiff_t end, ptrdiff_t &i, ptrdiff_t &j, ptrdiff_t &k, Compare cmp);

template <HasCompareOps T, typename Compare>
ptrdiff_t merge_lo_right(T* arr, std::vector<T> &left, ptrdiff_t start, ptrdiff_t mid, ptrdiff_t end, ptrdiff_t &i, ptrdiff_t &j, ptrdiff_t &k, Compare cmp);

template <HasCompareOps T, typename Compare>
void merge_lo(T* arr, ptrdiff_t start, ptrdiff_t mid, ptrdiff_t end, Compare cmp);

template <HasCompareOps T, typename Compare>
ptrdiff_t merge_hi_left(T* arr, std::vector<T> &right, ptrdiff_t start, ptrdiff_t mid, ptrdiff_t end, ptrdiff_t &i, ptrdiff_t &j, ptrdiff_t &k, Compare cmp);

template <HasCompareOps T, typename Compare>
ptrdiff_t merge_hi_right(T* arr, std::vector<T> &right, ptrdiff_t start, ptrdiff_t mid, ptrdiff_t end, ptrdiff_t &i, ptrdiff_t &j, ptrdiff_t &k, Compare cmp);

template <HasCompareOps T, typename Compare>
void merge_hi(T* arr, ptrdiff_t start, ptrdiff_t mid, ptrdiff_t end, Compare cmp);

}

}

#include "tim_sort.tpp"

#endif