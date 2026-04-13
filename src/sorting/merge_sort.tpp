#include "../algo_utils.hpp"
#include <vector>
#include <cstddef>

namespace algo_imp::sorting {

template <HasCompareOps T, typename Compare>
void merge_sort(T* arr, size_t start, size_t end, Compare cmp) 
{    
    if(start + 1 >= end) return;

    size_t mid = (start + end) >> 1;
    merge_sort(arr, start, mid, cmp);
    merge_sort(arr, mid, end, cmp);
    merge(arr, start, mid, end, cmp);
}

template <HasCompareOps T, typename Compare>
void merge(T* arr, size_t start, size_t mid, size_t end, Compare cmp) 
{
    size_t n1 = mid - start;
    size_t n2 = end - mid;
    
    std::vector<T> left_vec(arr + start, arr + mid);
    std::vector<T> right_vec(arr + mid, arr + end);

    size_t i = 0, j = 0, k = start;
    while(i < n1 && j < n2) {
        if(cmp(right_vec[j], left_vec[i])) arr[k ++] = right_vec[j ++];
        else                               arr[k ++] = left_vec[i ++];
    }

    while(i < n1) arr[k ++] = left_vec[i ++];
    while(j < n2) arr[k ++] = right_vec[j ++];
}

}