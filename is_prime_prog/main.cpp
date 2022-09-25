#include <iostream>

using namespace std;

int main()
{
    int number;
    while (std::cin >> number)
    {
        int is_prime = 0;
        cout << number << " is a prime: ";
        for (int i = 2; i <= number / 2; ++i)
            if (number % i == 0)
                is_prime = 1;

        if (is_prime == 1)
            cout << "False" << endl;

        else
            cout << "True" << endl;
    }
}
