#include "../algo_utils.hpp"

namespace algo_imp::searching {

// Note: [start, end)
template <HasCompareOps T>
int64_t interpolation_search(T* arr, int64_t start, int64_t end, T target)
{
    int64_t left = start, right = end - 1, mid;

    while(arr[left] < arr[right] && arr[left] <= target && target <= arr[right]) {
        mid = left + ((right - left) * (target - arr[left])) / (arr[right] - arr[left]);

        if     (target > arr[mid]) left = mid + 1;
        else if(target < arr[mid]) right = mid - 1;
        else                        return mid;
    }

    if(target == arr[left]) return left;
    return -1;
}
   
}