#include "../algo_utils.hpp"
#include <cstddef>

namespace algo_imp::sorting {

template <HasCompareOps T, typename Compare>
void cocktail_sort(T* arr, size_t n, Compare cmp) 
{   
    // special case
    if(n == 0) return;

    ptrdiff_t left = 0, right = n - 1;
    bool swapped = true;

    while(swapped && left < right) {
        
        swapped = false;
        for(ptrdiff_t i = left; i < right; ++i) {
            if(cmp(arr[i + 1], arr[i])) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        right --;

        for(ptrdiff_t i = right; i > left; --i) {
            if(cmp(arr[i], arr[i - 1])) {
                std::swap(arr[i - 1], arr[i]);
                swapped = true;
            }
        }
        left ++;
    }
}

}