#include "../algo_utils.hpp"
#include <cmath>

namespace algo_imp::searching {

template <HasCompareOps T>
int64_t jump_search(T* arr, size_t n, T target)
{
    if(n == 0) return -1;
    if(n == 1) return (arr[0] == target) ? (0) : (-1);

    size_t sqrt_n = std::sqrt(n), a = 0, b = sqrt_n;

    while(arr[std::min(b, n - 1)] < target) {
        a = b;
        b += sqrt_n;
        if(a >= n) return -1;
    }

    // Some elements >= target
    while(arr[a] < target) {
        a ++;
        if(a == std::min(b + 1, n)) return -1;
    }

    if(arr[a] == target) return a;
    return -1;
}
   
}