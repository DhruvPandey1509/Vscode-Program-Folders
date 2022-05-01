#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int MissingNumber(vector<int> &a, int n)
    {
        long long sum = 0;

        for (int i = 0; i < n - 1; i++)
        {
            sum += a[i];
        }

        return ((n * (n + 1)) / 2) - sum;
    }
};