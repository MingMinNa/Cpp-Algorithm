#ifndef ALGO_INTERPOLATION_SEARCH
#define ALGO_INTERPOLATION_SEARCH

#include "../algo_utils.hpp"

namespace algo_imp::searching {

// Note: [start, end]
template <HasCompareOps T>
int64_t interpolation_search(T* arr, size_t n, const T &target);
   
}

#include "interpolation_search.tpp"

#endif