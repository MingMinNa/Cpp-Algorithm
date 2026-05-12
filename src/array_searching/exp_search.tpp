#include "../algo_utils.hpp"
#include "binary_search.hpp"

namespace algo_imp::searching {

template <HasCompareOps T>
int64_t exp_search(T* arr, size_t n, const T &target)
{
    if(n == 0) return -1;

    size_t exp = 1llu;
    for(; exp < n && arr[exp] <= target; exp <<= 1);

    size_t start = exp >> 1;
    size_t end   = std::min(exp, n); // Note: not inclusive in binary_search

    int64_t res = binary_search(arr + start, end - start, target);
    return (res == -1) ? (res) : (res + start);
}
   
}