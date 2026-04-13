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
    
    // Note: num_buckets must be at least 2.
    // General Case: size_t num_buckets = NUM_BUCKETS, div = 1;
    size_t num_buckets = NUM_BUCKETS, pow = 0;
    auto [min_ele, max_ele] = algo_imp::others::find_min_max(arr, n);
    bool done = false, descending = cmp(max_ele, min_ele);
    
    std::vector<T> temp_arr(arr, arr + n);

    // General Case: max_ele >= div
    while((max_ele >> pow) > 0) {
        
        memcpy(temp_arr.data(), arr, n * sizeof(T));

        // counting sort with buckets
        std::vector<T> buckets(num_buckets);

        for(size_t i = 0; i < n; ++i) {
            // General Case: size_t bucket_index = (temp_arr[i] / div) % num_buckets;
            size_t bucket_index = (temp_arr[i] >> pow) & (num_buckets - 1);
            buckets[bucket_index] ++;
        }

        ptrdiff_t start = 0, end = 0, step = 0;

        if(!descending) start = 1              , end = num_buckets, step =  1;
        else            start = num_buckets - 2, end = -1         , step = -1;

        for(ptrdiff_t i = start; i != end; i += step) {
            buckets[i] += buckets[i - step];
        }

        for(ptrdiff_t i = n - 1; i >= 0; --i) {
            // General Case: size_t bucket_index = (temp_arr[i] / div) % num_buckets;
            size_t bucket_index = (temp_arr[i] >> pow) & (num_buckets - 1);
            size_t rank = buckets[bucket_index];
            // rank is 1-based index.
            arr[TO_ZERO_BASE(rank)] = temp_arr[i];
            buckets[bucket_index] --;
        }

        // General Case: div *= num_buckets;
        pow += 8; 
    }
}

}