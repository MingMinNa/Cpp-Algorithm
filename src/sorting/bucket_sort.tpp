#include "../algo_utils.hpp"
#include <cstddef>

namespace algo_imp::sorting {

template <HasCompareOps T, typename Compare>
void bucket_sort(T* arr, size_t n, Compare cmp) 
{    
    for(size_t i = 1; i < n; ++i) {

        bool swapped = false;
        for(size_t j = 0; j < n - i; ++j) {
            if(cmp(arr[j + 1], arr[j])) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // The bucket sort is complete!
        if(!swapped) break;
    }
}

}