#ifndef ALGO_ORDER_STATISTIC
#define ALGO_ORDER_STATISTIC

#include "../algo_utils.hpp"
#include <utility>

namespace algo_imp::others {

template <HasCompareOps T>
T find_min(const T* arr, size_t n);

template <HasCompareOps T>
T find_max(const T* arr, size_t n);

template <HasCompareOps T>
std::pair<T, T> find_min_max(const T* arr, size_t n);

// Note: [start, end)
template <HasCompareOps T>
T find_ith_order(T* arr, size_t start, size_t end, size_t i);

}

#include "order_statistic.tpp"

#endif