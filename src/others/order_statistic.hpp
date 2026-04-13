#ifndef ALGO_ORDER_STATISTIC
#define ALGO_ORDER_STATISTIC

#include "../algo_utils.hpp"
#include <utility>

namespace algo_imp::others {

template <HasCompareOps T>
T find_min(const T* arr, uint64_t n);

template <HasCompareOps T>
T find_max(const T* arr, uint64_t n);

template <HasCompareOps T>
std::pair<T, T> find_min_max(const T* arr, uint64_t n);

template <HasCompareOps T>
T find_ith_order(T* arr, uint64_t start, uint64_t end, uint64_t i);

}

#include "order_statistic.tpp"

#endif