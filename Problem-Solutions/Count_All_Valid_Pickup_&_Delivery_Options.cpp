#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int countOrders(int n)
    {
        long mod = 1000000007;
        long res = 1;

        for (int i = 1; i <= n; i++)
        {
            res *= i;   // calculating n!
            res %= mod; // to avoid overflow;

            res *= (2 * i - 1); // choosing and arranging delivery task in 2n-1 places
            res %= mod;         // to avoid overflow
        }

        return res % mod;
    }
};