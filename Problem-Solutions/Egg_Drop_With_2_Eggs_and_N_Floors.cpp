#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int dp[1005][3];
    int solve(int n, int eggs)
    {
        if (dp[n][eggs] != -1)
            return dp[n][eggs];

        if (n <= 1 || eggs == 1)
            return n;

        int mn = 1e6;

        for (int i = 1; i <= n; i++)
        {
            // maximizing the minimum possible moves since we need to find the minimum possible moves in worst case scenerio
            mn = min(mn, max(solve(i - 1, eggs - 1), solve(n - i, eggs)) + 1);
        }
        return dp[n][eggs] = mn;
    }
    int twoEggDrop(int n)
    {
        memset(dp, -1, sizeof(dp));
        return solve(n, 2);
    }
};
