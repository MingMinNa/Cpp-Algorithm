#include "../algo_utils.hpp"

namespace algo_imp::searching {

template <HasCompareOps T>
int64_t linear_search(T* arr, size_t n, const T &target, bool sorted)
{
    for(size_t i = 0; i < n; ++i) {
        if(arr[i] == target)               return i;
        else if(sorted && arr[i] > target) break;
    }
    return -1;
}

}