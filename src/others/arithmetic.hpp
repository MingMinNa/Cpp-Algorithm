#ifndef ALGO_ARITHMETIC
#define ALGO_ARITHMETIC

#include "../algo_utils.hpp"
#include <vector>
#include <utility>
#include <cstdint>

namespace algo_imp::others {

namespace detail {

// For Miller–Rabin Primality Test
const uint64_t DETERMINISTIC_BASES_64BIT[] = {
    2llu, 325llu, 9375llu, 28178llu, 450775llu, 9780504llu, 1795265022llu
}; 

uint64_t ctzll(uint64_t n);

}

// Calculate (a + b) % mod.
// If the mod value is zero, then no modulo operation is needed.
uint64_t add_mod(uint64_t a, uint64_t b, uint64_t mod = 0);

// Calculate (a * b) % mod.
// If the mod value is zero, then no modulo operation is needed.
uint64_t mul_mod(uint64_t a, uint64_t b, uint64_t mod = 0);

// Calculate pow(base, exp) % mod.
// If the mod value is zero, then no modulo operation is needed.
uint64_t fast_exp(uint64_t base, uint64_t exp, uint64_t mod = 0);

uint64_t fast_exp_iter(uint64_t base, uint64_t exp, uint64_t mod = 0);

// Calculate fib(n).
uint64_t fast_fib(uint64_t n, uint64_t mod = 0);

// Stein's Algorithm
uint64_t binary_gcd(uint64_t a, uint64_t b);

// Euclidean Algorithm
uint64_t euclidean_gcd(uint64_t a, uint64_t b); 

// Extended Euclidean Algorithm
// Find x and y such that ax + by = gcd(a, b).
std::pair<int64_t, int64_t> extended_gcd(int64_t a, int64_t b); 

uint64_t lcm(uint64_t a, uint64_t b);

// Sieve of Eratosthenes
// Find all the prime numbers <= n
std::vector<uint64_t> eratos_sieve(uint64_t n);

// Linear Sieve Algorithm
// Find all the prime numbers <= n
std::vector<uint64_t> linear_sieve(uint64_t n);

// Miller–Rabin Primality Test
// Check whether n is a prime.
bool is_prime(uint64_t n);

}

#include "arithmetic.tpp"

#endif