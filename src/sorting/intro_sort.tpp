#include "../algo_utils.hpp"
#include "insertion_sort.hpp"
#include "heap_sort.hpp"
#include "quick_sort.hpp"
#include <cstddef>
#include <cmath>

namespace algo_imp::sorting {

template <HasCompareOps T, typename Compare>
void intro_sort(T* arr, size_t n, Compare cmp) 
{    
    // special case
    if(n == 0) return;
    size_t max_depth = static_cast<size_t>(std::log2(n)) >> 1;
    detail::intro_sort_depth(arr, 0, n, max_depth, cmp);
}

namespace detail {

template <HasCompareOps T, typename Compare>
void intro_sort_depth(T* arr, size_t start, size_t end, size_t depth, Compare cmp) 
{    
    size_t n = end - start;

    if(n < 16) {
        insertion_sort(arr + start, n, cmp);
        return;
    }
    else if(depth == 0) {
        heap_sort(arr + start, n, cmp);
        return;
    }

    size_t pivot_index = partition(arr, start, end, true, cmp);
    if(pivot_index > start)   intro_sort_depth(arr, start, pivot_index, depth - 1, cmp);
    if(pivot_index + 1 < end) intro_sort_depth(arr, pivot_index + 1, end, depth - 1, cmp);
}

}

}