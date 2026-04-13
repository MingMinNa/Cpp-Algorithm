#include "../algo_utils.hpp"
#include <vector>
#include <cstddef>

namespace algo_imp::sorting {

template <HasCompareOps T, typename Compare>
void quick_sort(T* arr, size_t start, size_t end, bool random_pivot, Compare cmp)
{    
    if(start + 1 >= end) return;
    
    size_t pivot_index = partition(arr, start, end, random_pivot, cmp);
    if(pivot_index > start)   quick_sort(arr, start, pivot_index, random_pivot, cmp);
    if(pivot_index + 1 < end) quick_sort(arr, pivot_index + 1, end, random_pivot, cmp);
}

template <HasCompareOps T, typename Compare>
size_t partition(T* arr, size_t start, size_t end, bool random_pivot, Compare cmp)
{   
    size_t last = end - 1;

    if(random_pivot) {
        size_t rand_index = random_generate(start, last);
        std::swap(arr[last], arr[rand_index]);
    }

    T pivot = arr[last];
    size_t i = start;

    for(size_t j = start; j < last; ++j) {
        if(cmp(arr[j], pivot)) {
            std::swap(arr[i], arr[j]);
            ++i;
        }
    }

    std::swap(arr[last], arr[i]);
    return i;
}

}