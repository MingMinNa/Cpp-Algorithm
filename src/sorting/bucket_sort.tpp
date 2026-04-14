#include "../algo_utils.hpp"
#include "insertion_sort.hpp"
#include <cmath>
#include <cstddef>

namespace algo_imp::sorting {

template <Numeric T, typename Compare>
void bucket_sort(T* arr, size_t n, size_t num_buckets, Compare cmp) 
{    
    // special case
    if(n == 0) return;

    // if num_buckets is not specified, set it to sqrt(n) + 1
    if(num_buckets == 0) {
        num_buckets = std::min(MAX_NUM_BUCKETS, static_cast<size_t>(std::sqrt(n)) + 1);
    }

    auto [min_ele, max_ele] = algo_imp::others::find_min_max(arr, n);
    bool descending = cmp(max_ele, min_ele);

    // special case II: all elements are the same.
    if(min_ele == max_ele) return;

    std::vector<std::vector<T>> buckets(num_buckets);
    size_t range = static_cast<size_t>(max_ele) - min_ele;

    for(size_t i = 0; i < n; ++i) {
        size_t bucket_index = 1.0 * (static_cast<size_t>(arr[i]) - min_ele) / range * num_buckets;
        if(bucket_index >= num_buckets) bucket_index = num_buckets - 1;
        buckets[bucket_index].push_back(arr[i]);
    }

    for(auto &bucket : buckets) {
        insertion_sort(bucket.data(), bucket.size(), cmp);
    }

    ptrdiff_t start = 0, end = 0, step = 0, index = 0;

    if(!descending) start = 0              , end = num_buckets, step =  1;
    else            start = num_buckets - 1, end = -1         , step = -1;    

    for(ptrdiff_t i = start; i != end; i += step) {
        for(auto &e : buckets[i]) {
            arr[index] = e;
            ++ index;
        }
    }
}

}