#include "../algo_utils.hpp"
#include <cstddef>

namespace algo_imp::sorting {

template <HasCompareOps T, typename Compare>
void selection_sort(T* arr, size_t n, Compare cmp) 
{
    for(size_t i = 1; i < n; ++i) {
        
        size_t index = i - 1;
        for(size_t j = i; j < n; ++j) {
            if(cmp(arr[j], arr[index])) {
                index = j;
            }
        }

        std::swap(arr[i - 1], arr[index]);
    }
}

}