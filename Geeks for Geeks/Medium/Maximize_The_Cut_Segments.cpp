#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n + 1);
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            dp[i] = -1;
            if (i - x >= 0 and dp[i - x] != -1)
            {
                dp[i] = max(dp[i], dp[i - x] + 1);
            }
            if (i - y >= 0 and dp[i - y] != -1)
            {
                dp[i] = max(dp[i], dp[i - y] + 1);
            }
            if (i - z >= 0 and dp[i - z] != -1)
            {
                dp[i] = max(dp[i], dp[i - z] + 1);
            }
        }

        if (dp[n] == -1)
            return 0;

        return dp[n];
    }
};