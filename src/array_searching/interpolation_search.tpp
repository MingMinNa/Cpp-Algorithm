#include "../algo_utils.hpp"

namespace algo_imp::searching {

// Note: [start, end)
template <HasCompareOps T>
int64_t interpolation_search(T* arr, size_t n, const T &target)
{
    if(n == 0) return -1;
    ptrdiff_t left = 0, right = n - 1, mid;

    while(
        arr[left] < arr[right] && 
        arr[left] <= target && 
        target <= arr[right]
    ) {
        mid = left + ((right - left) * (target - arr[left])) / (arr[right] - arr[left]);

        if     (target > arr[mid]) left = mid + 1;
        else if(target < arr[mid]) right = mid - 1;
        else                       return mid;
    }

    if(left < static_cast<ptrdiff_t>(n) && target == arr[left]) return left;
    return -1;
}
   
}