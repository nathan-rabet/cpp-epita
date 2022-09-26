#include <iostream>
#include <math.h>

#define DUMMY_THREASHOLD 10000
#define MR_NB_TESTS 10

using namespace std;

size_t exponential_modulus(size_t base, size_t exponent, size_t modulus)
{
    size_t result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % modulus;
        }
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

bool miller_rabin_prime(size_t p)
{
    // Using Miller-Rabin primality test
    if (p < 2)
        return false;
    if (p != 2 && p % 2 == 0)
        return false;

    // Find s & d where `p - 1 = (2^s)×d`, s > 0.
    size_t s = 0;
    size_t d = p - 1;
    while (d % 2 == 0)
    {
        d /= 2;
        s++;
    }

    // Test `p` for primality `MR_NB_TESTS` times.
    for (size_t i = 0; i < MR_NB_TESTS; i++)
    {
        // Generate a random number `a` in the range [2, p - 2].
        size_t a = 2 + rand() % (p - 4);

        // Compute `x = a^d mod p`.
        size_t a_exp_d = exponential_modulus(a, d, p);
        if (a_exp_d == 1)
            continue;

        // Repeat `s - 1` times.
        bool test_2 = false;
        for (size_t r = 0; r < s && !test_2; r++)
        {
            // Compute `x = x^2 mod p`.
            test_2 = exponential_modulus(a_exp_d, pow(2,r) , p) == p - 1;
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
        if (p % i == 0)
            return false;
    return true;
}

int main()
{
    size_t number;
    while (std::cin >> number)
    {
        bool is_prime;
        if (number <= DUMMY_THREASHOLD)
            is_prime = dummy_prime(number);
        else
            is_prime = miller_rabin_prime(number);

        cout << number << " is a prime: " << (is_prime ? "True" : "False")
             << endl;
    }
}
