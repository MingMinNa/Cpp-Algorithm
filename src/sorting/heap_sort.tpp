#include "../algo_utils.hpp"
#include <cstddef>

namespace algo_imp::sorting {

template <HasCompareOps T, typename Compare>
void heap_sort(T* arr, size_t n, Compare cmp) 
{
    build_heap<T, Compare>(arr, n, cmp);
    for(size_t i = n; i > 0; --i) {
        std::swap(arr[TO_ZERO_BASE(i)], arr[0]);
        heapify(arr, i - 1, 1, cmp);
    }
}

template <HasCompareOps T, typename Compare>
void heapify(T* arr, size_t n, size_t curr_index, Compare cmp) 
{    
    while(true) {
        size_t left  = curr_index << 1;
        size_t right = left + 1;
        size_t next_index = curr_index;

        // Note: left and right are 1-based index.
        if(left  <= n && cmp(arr[TO_ZERO_BASE(next_index)], arr[TO_ZERO_BASE(left)] )) next_index = left;
        if(right <= n && cmp(arr[TO_ZERO_BASE(next_index)], arr[TO_ZERO_BASE(right)])) next_index = right;

        if(next_index == curr_index) return;

        std::swap(arr[TO_ZERO_BASE(curr_index)], arr[TO_ZERO_BASE(next_index)]);
        curr_index = next_index;
    }
}

template <HasCompareOps T, typename Compare>
void build_heap(T* arr, size_t n, Compare cmp) 
{
    for(size_t i = (n >> 1) + 1; i > 0; --i) {
        heapify(arr, n, i, cmp);
    }
}

}