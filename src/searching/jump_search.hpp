#ifndef ALGO_JUMP_SEARCH
#define ALGO_JUMP_SEARCH

#include "../algo_utils.hpp"

namespace algo_imp::searching {

template <HasCompareOps T>
int64_t jump_search(T* arr, size_t n, T target);
   
}

#include "jump_search.tpp"

#endif