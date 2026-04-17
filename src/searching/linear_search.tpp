#include "../algo_utils.hpp"

namespace algo_imp::searching {

template <HasCompareOps T>
int64_t linear_search(T* arr, size_t n, T target)
{
    for(int64_t i = 0; i < n; ++i) {
        if(arr[i] == target) return i;
    }
    return -1;
}

}