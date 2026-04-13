#include "../algo_utils.hpp"
#include <cstddef>

namespace algo_imp::sorting {

template <HasCompareOps T, typename Compare>
void insertion_sort(T* arr, size_t n, Compare cmp) 
{
    for(size_t i = 1; i < n; ++i) {

        size_t index = i;
        T key = arr[i];

        while(index > 0 && cmp(key, arr[index - 1])) {
            arr[index] = arr[index - 1];
            -- index;
        }

        arr[index] = key;
    }
}

}