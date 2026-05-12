#ifndef ALGO_EXP_SEARCH
#define ALGO_EXP_SEARCH

#include "../algo_utils.hpp"
#include "binary_search.hpp"

namespace algo_imp::searching {

template <HasCompareOps T>
int64_t exp_search(T* arr, size_t n, const T &target);
   
}

#include "exp_search.tpp"

#endif