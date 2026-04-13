#include "../algo_utils.hpp"
#include <cstddef>

namespace algo_imp::sorting {

template <HasCompareOps T, typename Compare>
void shell_sort(T* arr, size_t n, Compare cmp) 
{    
    // special case
    if(n == 0) return;

    size_t start = 0, size = PRATT_GAP_SEQUENCE.size();
    for(size_t jump = size >> 1; jump >= 1; jump >>= 1) {
        while(start + jump < size && PRATT_GAP_SEQUENCE[start + jump] < n) {
            start += jump;
        }
    }

    for(ptrdiff_t gap_index = start; gap_index >= 0; gap_index --) {

        size_t gap = PRATT_GAP_SEQUENCE[gap_index];

        // insertion sort
        for(size_t i = gap; i < n; ++i) {

            size_t index = i;
            T key = arr[i];

            while(index >= gap && cmp(key, arr[index - gap])) {
                arr[index] = arr[index - gap];
                index -= gap;
            }
            
            arr[index] = key;
        }
    }
}

}