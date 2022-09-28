#include <cmath>
#include <iostream>

#define MR_NB_TESTS 15
#define DUMMY_THREASHOLD (MR_NB_TESTS * MR_NB_TESTS)

#define MAX(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

// Create a modulo function that is overflowsafe
size_t modulo(size_t a, size_t b)
{
    return (a % b + b) % b;
}

size_t exponential_modulus(size_t base, size_t exponent, size_t modulus)
{
    size_t result = 1;
    while (exponent > 0)
    {
        if (modulo(exponent, 2) == 1)
            result = modulo(result * base, modulus);

        exponent = exponent >> 1;
        base = modulo(base * base, modulus);
    }
    return result;
}

bool miller_rabin_prime(size_t p)
{
    // Using Miller-Rabin primality test
    // Find s & d where `p - 1 = (2^s)×d`, s > 0.
    size_t s = 0;
    size_t d = p - 1;
    while (modulo(d, 2) == 0)
    {
        d /= 2;
        s++;
    }

    // Test `p` for primality `MR_NB_TESTS` times.
    for (size_t i = 0; i < MR_NB_TESTS; i++)
    {
        // Generate a random number `a` in the range [2, p - 2].
        size_t a = 2 + modulo(rand(), MAX(p - 4, SIZE_MAX / d - 1 - 2));

        // Compute `x = a^d mod p`.
        size_t a_exp_d = exponential_modulus(a, d, p);
        if (a_exp_d == 1)
            continue;

        // Repeat `s - 1` times.
        bool test_2 = false;
        for (size_t r = 0; r < s && !test_2; r++)
        {
            // Compute `x = x^2 mod p`.
            test_2 = exponential_modulus(a_exp_d, pow(2, r), p) == p - 1;
        }

        // If `x` is not `p - 1`, then `a` is a witness for the compositeness of
        // `p`.
        if (!test_2)
            return false;
    }

    return true;
}

bool dummy_prime(size_t p)
{
    for (int i = 2; i * i <= p; ++i)
        if (modulo(p, i) == 0)
            return false;
    return true;
}

int main()
{
    size_t number;
    while (std::cin >> number)
    {
        bool is_prime;

        if (number < 2 || number != 2 && modulo(number, 2) == 0)
            is_prime = false;
        else if (number < DUMMY_THREASHOLD)
            is_prime = dummy_prime(number);
        else
            is_prime = miller_rabin_prime(number);

        cout << number << " is a prime: " << (is_prime ? "True" : "False")
             << endl;
    }
}
