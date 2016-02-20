// File Name: lesson2-173-5.cpp
// Last Changed: 2/7/2016
// Student: Shane Kirkley

// Description: This program prints all prime numbers between 3 and 100

#include <iostream>
using namespace std;

int main()
{
    // Iterate over every odd number from 3 to 100
    for (int i = 3; i <= 100; i = i + 2)
    {
        for (int n = 2; n < i; n++)
        {
            // if i mod n = 0, then i is not prime.
            if (i % n == 0)
            {
                break;
            }

            // if n reaches half of i, then i is prime, no need to check higher.
            if (n >= i / 2)
            {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}
