#ifndef ALGO_TERNARY_SEARCH
#define ALGO_TERNARY_SEARCH

#include "../algo_utils.hpp"

namespace algo_imp::searching {

template <typename F>
double ternary_search(double left, double right, F func, bool min = true);

}

#include "ternary_search.tpp"

#endif 