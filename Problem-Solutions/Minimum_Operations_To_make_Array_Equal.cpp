#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minOperations(int n)
    {
        int res = 0;
        int m = n / 2;

        for (int i = 1; i <= m; i++)
        {
            res += 2 * i;
        }

        if (n % 2 == 0)
            res -= n / 2;

        return res;
    }
};