#ifndef ALGO_LINEAR_SEARCH
#define ALGO_LINEAR_SEARCH

#include "../algo_utils.hpp"

namespace algo_imp::searching {

template <HasCompareOps T>
int64_t linear_search(T* arr, size_t n, const T &target, bool sorted = false);

}

#include "linear_search.tpp"

#endif 