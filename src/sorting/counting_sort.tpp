#include "../algo_utils.hpp"
#include "../others/order_statistic.hpp"
#include <cstddef>
#include <stdexcept>

namespace algo_imp::sorting {

template <std::integral T, typename Compare>
void counting_sort(T* arr, size_t n, Compare cmp) 
{
    // special case
    if(n == 0) return;

    auto [min_ele, max_ele] = algo_imp::others::find_min_max(arr, n);
    size_t size = static_cast<size_t>(max_ele) - min_ele + 1;

    // overflow (e.g. max_ele == LLONG_MAX, min_ele == LLONG_MIN, max_ele - min_ele + 1 will be 0)
    if(size == 0) {
        throw std::runtime_error("Range computation overflow (max - min + 1)");
    }

    std::vector<size_t> counts(size);

    for(size_t i = 0; i < n; ++i) {
        counts[arr[i] - min_ele] ++;
    }

    // less   : descending = false;
    // greater: descending = true;
    bool descending = cmp(max_ele, min_ele);
    std::vector<T> temp_arr(arr, arr + n);
    
    ptrdiff_t start = 0, end = 0, step = 0;

    if(!descending) start = 1       , end = size, step =  1;
    else            start = size - 2, end = -1  , step = -1;

    for(ptrdiff_t i = start; i != end; i += step) {
        counts[i] += counts[i - step];
    }

    for(ptrdiff_t i = n - 1; i >= 0; --i) {
        size_t rank = counts[temp_arr[i] - min_ele];
        // rank is 1-based index.
        arr[TO_ZERO_BASE(rank)] = temp_arr[i];
        counts[temp_arr[i] - min_ele] --;
    }
}

}