#include "../headers.h"

/*
 *  Get all prime numbers upto a given number n
 */
vector<i64> sieve(int n)
{
    vector<int> arr(n + 1, 0);
    vector<i64> primes;

    for (int i = 2; i * i <= n; i++)
        if (arr[i] == 0)
            for (int j = i * i; j <= n; j += i)
                arr[j] = 1;

    for (int i = 2; i <= n; i++)
        if (arr[i] == 0)
            primes.push_back(i);

    return primes;
}
