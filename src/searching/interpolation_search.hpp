#ifndef ALGO_INTERPOLATION_SEARCH
#define ALGO_INTERPOLATION_SEARCH

#include "../algo_utils.hpp"

namespace algo_imp::searching {

// Note: [left, right]
template <HasCompareOps T>
int64_t interpolation_search(T* arr, int64_t start, int64_t end, T target);
   
}

#include "interpolation_search.tpp"

#endif