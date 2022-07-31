#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int nthUglyNumber(int n)
    {

        vector<int> dp(n + 1);

        dp[1] = 1;
        int ptr2 = 1, ptr3 = 1, ptr5 = 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = min({dp[ptr2] * 2, dp[ptr3] * 3, dp[ptr5] * 5});
            if (dp[i] == dp[ptr2] * 2)
                ptr2++;
            if (dp[i] == dp[ptr3] * 3)
                ptr3++;
            if (dp[i] == dp[ptr5] * 5)
                ptr5++;
        }

        return dp[n];
    }
};