#ifndef ALGO_UTILS
#define ALGO_UTILS

#include <limits>
#include <random>
#include <concepts>
#include <stdexcept>

// 1-based array index ↔︎ 0-based array index
#define TO_ZERO_BASE(x) ((x) - 1)
#define TO_ONE_BASE(x)  ((x) + 1)

namespace algo_imp {

template <typename T>
concept HasCompareOps = requires(T a, T b) {
    { a >  b } -> std::convertible_to<bool>;
    { a <  b } -> std::convertible_to<bool>;
    { a >= b } -> std::convertible_to<bool>;
    { a <= b } -> std::convertible_to<bool>;
    { a == b } -> std::convertible_to<bool>;
    { a != b } -> std::convertible_to<bool>;
};

template <typename T>
concept HasMinMax = requires {
    { std::numeric_limits<T>::max() } -> std::convertible_to<T>;
    { std::numeric_limits<T>::min() } -> std::convertible_to<T>;
};

template <typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

size_t random_generate(size_t lower_bound, size_t upper_bound) 
{
    if(lower_bound > upper_bound)
        throw std::runtime_error(
            "Lower bound must not exceed upper bound."
        );

    static std::mt19937_64 gen(std::random_device{}());
    std::uniform_int_distribution<size_t> dist(lower_bound, upper_bound);
    return dist(gen);
}

void check_array_nonempty(size_t n)
{
    if(n == 0) {
        throw std::runtime_error(
            "The array cannot be empty."
        );
    }
}

}

#endif