#include <cmath>
#include <iostream>

#define MR_NB_TESTS 50
#define DUMMY_THREASHOLD (MR_NB_TESTS * MR_NB_TESTS)

#define MAX(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef __uint128_t data_t;

// Create a modulo function that is overflowsafe
data_t modulo(data_t a, data_t b)
{
    return (a % b + b) % b;
}

data_t fast_exponentation(data_t a, data_t b)
{
    if (b < 1)
        return 1;
    if (b % 2 == 0)
        return fast_exponentation(a * a, b / 2);
    else
        return a * fast_exponentation(a * a, b / 2);
}

data_t exponential_modulus(data_t base, data_t exponent, data_t modulus)
{
    data_t result = 1;
    while (exponent > 0)
    {
        if (modulo(exponent, 2) == 1)
            result = modulo(result * base, modulus);

        exponent = exponent >> 1;
        base = modulo(base * base, modulus);
    }
    return result;
}

bool miller_rabin_prime(data_t p)
{
    if (p < 2)
        return false;

    // Using Miller-Rabin primality test
    // Find s & d where `p - 1 = (2^s)×d`, s > 0.
    data_t s = 0;
    data_t d = p - 1;
    while (modulo(d, 2) == 0)
    {
        d /= 2;
        s++;
    }

    // Test `p` for primality `MR_NB_TESTS` times.
    for (data_t i = 0; i < MR_NB_TESTS; i++)
    {
        // Generate a random number `a` in the range [2, p - 2].
        data_t a = 2 + modulo(rand(), MAX(p - 4, SIZE_MAX / d - 1 - 2));

        // Compute `x = a^d mod p`.
        data_t a_exp_d = exponential_modulus(a, d, p);
        if (a_exp_d == 1)
            continue;

        // Repeat `s - 1` times.
        bool test_2 = false;
        for (data_t r = 0; r < s && !test_2; r++)
        {
            // Compute `x = x^2 mod p`.
            test_2 = exponential_modulus(a_exp_d, fast_exponentation(2, r), p)
                == p - 1;
        }

        // If `x` is not `p - 1`, then `a` is a witness for the compositeness of
        // `p`.
        if (!test_2)
            return false;
    }

    return true;
}

bool dummy_prime(data_t p)
{
    if (p < 2)
        return false;
    for (int i = 2; i * i <= p; ++i)
        if (modulo(p, i) == 0)
            return false;
    return true;
}

int main()
{
    data_t computedNumber;
    size_t inputNumber;

    // Read line from stdin and convert to data_t
    while (cin >> inputNumber)
    {
        bool is_prime;
        computedNumber = inputNumber;
        if (computedNumber < 2
            || computedNumber != 2 && modulo(computedNumber, 2) == 0)
            is_prime = false;

        // Check if number is prime
        is_prime = computedNumber < DUMMY_THREASHOLD
            ? dummy_prime(computedNumber)
            : miller_rabin_prime(computedNumber);

        // Print result
        cout << inputNumber << " is a prime: " << (is_prime ? "True" : "False")
             << endl;
    }
}
