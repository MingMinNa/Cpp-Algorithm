#include "../algo_utils.hpp"
#include "../sorting/quick_sort.hpp"
#include <utility>
#include <cstddef>
#include <stdexcept>

namespace algo_imp::others {

template <HasCompareOps T>
T find_min(const T* arr, size_t n)
{
    check_array_nonempty(n);
    
    size_t curr = 0;
    for(size_t i = 1; i < n; ++i) {
        if(arr[i] < arr[curr]) curr = i;
    }
    return arr[curr];
}

template <HasCompareOps T>
T find_max(const T* arr, size_t n)
{
    check_array_nonempty(n);

    size_t curr = 0;
    for(size_t i = 1; i < n; ++i) {
        if(arr[i] > arr[curr]) curr = i;
    }
    return arr[curr];
}

template <HasCompareOps T>
std::pair<T, T> find_min_max(const T* arr, size_t n)
{
    check_array_nonempty(n);

    T max_ele, min_ele, larger, smaller;
    size_t i;

    if(n % 2 == 0) {
        max_ele = (arr[0] > arr[1]) ? (arr[0]) : (arr[1]);
        min_ele = (arr[0] > arr[1]) ? (arr[1]) : (arr[0]);
        i = 2;
    }
    else {
        max_ele = arr[0];
        min_ele = arr[0];
        i = 1;
    }

    for(; i < n; i += 2) {
        if(arr[i] < arr[i + 1]) {
            larger  = arr[i + 1];
            smaller = arr[i];
        }
        else {
            larger  = arr[i];
            smaller = arr[i + 1];
        }
        if(larger  > max_ele) max_ele = larger;
        if(smaller < min_ele) min_ele = smaller;
    }
    return {min_ele, max_ele};
}

template <HasCompareOps T>
T find_ith_order(T* arr, size_t start, size_t end, size_t i)
{
    if(start >= end) {
        throw std::runtime_error("`start` must be less than `end`.");
    }

    size_t n = end - start;
    if     (i <= 1) return find_min(arr + start, n);
    else if(i >= n) return find_max(arr + start, n);

    size_t mid = algo_imp::sorting::partition<T>(arr, start, end, false);
    size_t rank = mid - start + 1;

    if     (rank == i) return arr[mid];
    else if(rank >  i) return find_ith_order(arr, start, mid, i);
    return find_ith_order(arr, mid + 1, end, i - rank);
}

}