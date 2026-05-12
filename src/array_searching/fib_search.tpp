#include "../algo_utils.hpp"

namespace algo_imp::searching {

template <HasCompareOps T>
int64_t fib_search(T* arr, size_t n, const T &target)
{
    if(n == 0) return -1;

    // Fibonacci numbers
    size_t fib_0 = 0, fib_1 = 1, fib_2 = fib_0 + fib_1;

    while(fib_2 < n) {
        fib_0 = fib_1;
        fib_1 = fib_2;
        fib_2 = fib_0 + fib_1;
    }

    int64_t index = -1;

    while(fib_2 > 1) {

        int64_t i = std::min<int64_t>(index + fib_0, n - 1);

        if(arr[i] < target) {
            fib_2 = fib_1;
            fib_1 = fib_0;
            fib_0 = fib_2 - fib_1;
            index = i; 
        }
        else if(arr[i] > target) {
            fib_2 = fib_0;
            fib_1 = fib_1 - fib_0;
            fib_0 = fib_2 - fib_1;
        }
        else {
            return i;
        }
    }

    if(
        fib_1 && 
        index + 1 < static_cast<int64_t>(n) && 
        arr[index + 1] == target
    ) return index + 1;

    return -1;
}
   
}