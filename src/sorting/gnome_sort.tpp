#include "../algo_utils.hpp"
#include <cstddef>

namespace algo_imp::sorting {

template <HasCompareOps T, typename Compare>
void gnome_sort(T* arr, size_t n, Compare cmp) 
{    
    size_t pos = 0;
    while(pos < n) {
        if(pos == 0 || !cmp(arr[pos], arr[pos - 1])) {
            ++ pos;
        }
        else {
            std::swap(arr[pos - 1], arr[pos]);
            -- pos;
        }
    }
}

}