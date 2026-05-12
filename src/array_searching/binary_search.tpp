#include "../algo_utils.hpp"

namespace algo_imp::searching {

namespace detail {

template <HasCompareOps T, typename Compare>
int64_t bound_subroutine(T* arr, size_t n, const T &target, Compare cmp)
{
    if(n == 0) return -1;

    int64_t index = -1;
    for(int64_t jump = n >> 1; jump >= 1; jump >>= 1) {
        while(index + jump < static_cast<int64_t>(n) && cmp(arr[index + jump], target)) {
            index += jump;
        }
    }
    return index + 1;
}

}

template <HasCompareOps T>
int64_t binary_search(T* arr, size_t n, const T &target)
{
    int64_t index = lower_bound<T>(arr, n, target);
    if (
        index < 0 || 
        index >= static_cast<int64_t>(n) || 
        arr[index] != target
    ) return -1;
    return index;
}

template <HasCompareOps T>
int64_t lower_bound(T* arr, size_t n, const T &target)
{
    return detail::bound_subroutine(arr, n, target, std::less<T>());
}

template <HasCompareOps T>
int64_t upper_bound(T* arr, size_t n, const T &target)
{
    return detail::bound_subroutine(arr, n, target, std::less_equal<T>());
}

template <HasCompareOps T>
int64_t bitonic_search(T* arr, size_t n, const T &target)
{
    int64_t left = 0, right = n - 1, mid;

    while(left < right) {
        mid = (left + right) >> 1;
        if(arr[mid] < arr[mid + 1]) left = mid + 1;
        else                        right = mid;
    }
    return left;
}

}
