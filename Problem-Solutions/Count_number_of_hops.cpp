#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    // Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        vector<long long> dp(n + 1, 0);

        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                if (i - j >= 0)
                {
                    dp[i] += dp[i - j];
                    dp[i] %= 1000000007;
                }
            }
        }

        return dp[n];
    }
};