#include "../algo_utils.hpp"
#include "../others/order_statistic.hpp"
#include <vector>
#include <cstddef>
#include <concepts>

namespace algo_imp::sorting {

template <std::unsigned_integral T, typename Compare>
void radix_sort(T* arr, size_t n, Compare cmp) 
{    
    // special case
    if(n == 0) return;
    
    // Note: radix must be at least 2.
    // General Case: size_t radix = ..., div = 1;
    size_t radix = RADIX, pow = 0;
    auto [min_ele, max_ele] = algo_imp::others::find_min_max(arr, n);
    bool descending = cmp(max_ele, min_ele);
    
    std::vector<T> temp_arr(arr, arr + n);

    // General Case: max_ele >= div
    while((max_ele >> pow) > 0) {
        
        memcpy(temp_arr.data(), arr, n * sizeof(T));

        // counting sort
        std::vector<T> counts(radix);

        for(size_t i = 0; i < n; ++i) {
            // General Case: size_t radix_index = (temp_arr[i] / div) % radix;
            size_t radix_index = (temp_arr[i] >> pow) & (radix - 1);
            counts[radix_index] ++;
        }

        ptrdiff_t start = 0, end = 0, step = 0;

        if(!descending) start = 1        , end = radix, step =  1;
        else            start = radix - 2, end = -1   , step = -1;

        for(ptrdiff_t i = start; i != end; i += step) {
            counts[i] += counts[i - step];
        }

        for(ptrdiff_t i = n - 1; i >= 0; --i) {
            // General Case: size_t radix_index = (temp_arr[i] / div) % radix;
            size_t radix_index = (temp_arr[i] >> pow) & (radix - 1);
            size_t rank = counts[radix_index];
            // rank is 1-based index.
            arr[TO_ZERO_BASE(rank)] = temp_arr[i];
            counts[radix_index] --;
        }

        // General Case: div *= radix;
        pow += 8; 
    }
}

}