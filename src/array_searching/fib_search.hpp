#ifndef ALGO_FIB_SEARCH
#define ALGO_FIB_SEARCH

#include "../algo_utils.hpp"

namespace algo_imp::searching {

template <HasCompareOps T>
int64_t fib_search(T* arr, size_t n, const T &target);
   
}

#include "fib_search.tpp"

#endif