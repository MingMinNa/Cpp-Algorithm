#include "../algo_utils.hpp"

namespace algo_imp::searching {

template <typename F>
double ternary_search(double left, double right, F func, bool min = true)
{
    const double eps = 1e-9;
    while(right - left > eps) {

        double p1 = left + (right - left) / 3.0;
        double p2 = left + 2.0 * (right - left) / 3.0;

        if(min == (func(p1) < func(p2))) right = p2;
        else                             left = p1;
    }
    return (left + right) / 2.0;
}

}