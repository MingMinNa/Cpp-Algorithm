#include "../algo_utils.hpp"
#include <cmath>
#include <vector>
#include <utility>
#include <cstdint>
#include <stdexcept>

namespace algo_imp::others {

namespace detail {

uint64_t ctzll(uint64_t n) 
{
    if(n == 0) return 64;

    uint64_t i = 0;
    while(!(n & 1)) {
        n >>= 1;
        ++ i;
    }
    return i;
}

}

uint64_t add_mod(uint64_t a, uint64_t b, uint64_t mod)
{
    // special case
    if(mod == 0) {
        if(a > UINT64_MAX - b) 
            throw std::overflow_error("a + b is greater than UINT64_MAX.");
        return a + b;
    }

    a %= mod;
    b %= mod;
    return (a >= mod - b) ? (a + b - mod) : (a + b);
}

uint64_t mul_mod(uint64_t a, uint64_t b, uint64_t mod)
{
    // special case
    if(mod == 0) {
        // a * b >= UINT64_MAX (but a * b may overflow)
        if(a != 0 && b != 0 && a > UINT64_MAX / b) 
            throw std::overflow_error("a x b is greater than UINT64_MAX.");
        return a * b;
    }

    if(a % mod == 0 || b % mod == 0) return 0;

    a %= mod;
    b %= mod;

    uint64_t res = 0;
    while(b > 0) {
        if(b & 1) {
            // the code below is the same as "res = (res + a) % mod;"
            if(res >= mod - a) res = res - (mod - a);
            else               res += a;
        }

        // the code below is the same as "a = (a << 1) % mod;"
        if(a >= mod - a) a = a - (mod - a);
        else             a <<= 1;
        b >>= 1;
    }

    return res;
}

uint64_t fast_exp(uint64_t base, uint64_t exp, uint64_t mod)
{
    if(mod == 1)  return 0; // Any value % 1 = 0
    if(exp == 0)  return 1; // 0^0 = 1 (special case)
    if(mod >  0) base %= mod;

    uint64_t res = fast_exp(base, exp >> 1, mod);
    res = mul_mod(res, res, mod);
    if(exp & 1) res = mul_mod(res, base, mod);

    return res;
}

uint64_t fast_exp_iter(uint64_t base, uint64_t exp, uint64_t mod)
{
    if(mod == 1)  return 0; // Any value % 1 = 0
    if(exp == 0)  return 1; // 0^0 = 1 (special case)
    if(mod >  0)  base %= mod; 

    uint64_t res = 1;
    while(exp > 0) {
        if(exp & 1) {
            res = mul_mod(res, base, mod);
        }
        
        base = mul_mod(base, base, mod);
        exp >>= 1;
    }
    return res;
}

uint64_t fast_fib(uint64_t n, uint64_t mod)
{
    // Base cases: f(0) = 0, f(1) = 1
    if(n <= 1) return n;

    // SOM (Second Order Matrix)
    using SOM = struct {
        uint64_t a00, a01;
        uint64_t a10, a11;
    };

    auto SOM_mul = [&](const SOM& x, const SOM& y) -> SOM 
    {
        return {
            add_mod(mul_mod(x.a00, y.a00, mod), mul_mod(x.a01, y.a10, mod), mod),
            add_mod(mul_mod(x.a00, y.a01, mod), mul_mod(x.a01, y.a11, mod), mod),
            add_mod(mul_mod(x.a10, y.a00, mod), mul_mod(x.a11, y.a10, mod), mod),
            add_mod(mul_mod(x.a10, y.a01, mod), mul_mod(x.a11, y.a11, mod), mod)
        };
    };

    auto fast_mat = [&](auto&& self, uint64_t n) -> SOM 
    {
        SOM base = {
            .a00 = 1, .a01 = 1,
            .a10 = 1, .a11 = 0
        };

        if(n == 0) {        
            // 2x2 unit matrix
            return {
                .a00 = 1, .a01 = 0,
                .a10 = 0, .a11 = 1
            };
        }

        if(n == 1) {
            return base;
        }

        SOM t = self(self, n >> 1), res = SOM_mul(t, t);
        if(n & 1) res = SOM_mul(res, base);
        return res;
    };

    SOM res = fast_mat(fast_mat, n - 1);
    return res.a00;
}

uint64_t binary_gcd(uint64_t a, uint64_t b)
{
    if(a == 0 || b == 0) return a | b;

    // 1 << shift is common divisor.
    size_t shift = detail::ctzll(a | b);
    a >>= detail::ctzll(a);

    while(b != 0) {
        b >>= detail::ctzll(b);
        if(a > b) std::swap(a, b);
        b -= a;
    }

    return a << shift;
}

uint64_t euclidean_gcd(uint64_t a, uint64_t b)
{
    if(a == 0 || b == 0) return a | b;
    if(a < b) std::swap(a, b);

    while(b > 0) {
        uint64_t t = b;
        b = a % b;
        a = t;
    }
    return a;
}

std::pair<int64_t, int64_t> extended_gcd(int64_t a, int64_t b)
{
    if(b == 0) return {1, 0};

    auto [x2, y2] = extended_gcd(b, a % b);
    return {y2, x2 - (a / b) * y2};
}

uint64_t lcm(uint64_t a, uint64_t b) 
{
    if(a == 0 || b == 0) return 0;
    // uint64_t ab_gcd = binary_gcd(a, b);
    uint64_t ab_gcd = euclidean_gcd(a, b);

    // gcd(a, b) * lcm(a, b) = a * b => lcm(a, b) = (a / gcd(a, b)) * b;
    // If lcm(a, b) > UINT64_MAX, then (a / gcd(a, b)) > UINT_MAX / b;
    if(a / ab_gcd > UINT64_MAX / b) {
        throw std::overflow_error("lcm(a, b) is greater than UINT64_MAX.");
    }
    return (a / ab_gcd) * b;
}

std::vector<uint64_t> eratos_sieve(uint64_t n)
{
    if(n <= 1) return {};

    uint64_t i;
    std::vector<char> prime_table(n + 1, 1);
    std::vector<uint64_t> primes;

    prime_table[0] = prime_table[1] = 0;
    for(i = 2; i * i <= n; ++i) {
        if(prime_table[i] == 0) continue;

        primes.push_back(i);
        for(uint64_t j = i * i; j <= n; j += i) {
            prime_table[j] = 0;
        }
    }

    for(; i <= n; ++i) {
        if(prime_table[i] == 1) {
            primes.push_back(i);
        }
    }

    return primes;
}

std::vector<uint64_t> linear_sieve(uint64_t n)
{
    std::vector<uint64_t> primes;
    std::vector<uint64_t> spf(n + 1, 0); // smallest prime factor

    for(uint64_t i = 2; i <= n; ++i) {
        if(spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }

        for(uint64_t p : primes) {
            // Ensure each composite i * p is generated only once.
            // Only allow primes p <= spf[i], so that p is the smallest prime factor of i * p.
            if(p > spf[i] || i * p > n) break;
            spf[i * p] = p;
        }
    }

    return primes;
}

bool is_prime(uint64_t n)
{
    if(n <= 2)   return n == 2;
    if(!(n & 1)) return false;

    uint64_t s = detail::ctzll(n - 1), d = (n - 1) >> s; 

    for(uint64_t base : detail::DETERMINISTIC_BASES_64BIT) {

        if(base >= n) break;
        bool pass = false;

        // x = base^(d) mod n;
        uint64_t x = fast_exp(base, d, n);
        if (x == 1 || x == n - 1) continue;

        for(uint64_t i = 1; i < s; ++i) {
            // x = base^(d * 2^i) mod n => x = [x_prev]^2 mod n
            x = mul_mod(x, x, n);
            if(x == n - 1) {
                pass = true;
                break;
            }
        }

        if(pass == false) return false;
    }
    return true;
}

}