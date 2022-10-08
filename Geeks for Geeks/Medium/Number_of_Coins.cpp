#include "bits/stdc++.h"
using namespace std;

// Dp (Tabulation + Space Optimization)
// T.C :- O(n^2)   S.C :- O(n)
class Solution
{
public:
    int minCoins(int coins[], int n, int target)
    {
        vector<int> prev(target + 1, 0), curr(target + 1, 0);
        for (int t = 0; t <= target; t++)
        {
            if (t % coins[0] == 0)
                prev[t] = t / coins[0];
            else
                prev[t] = 1e9;
        }

        for (int i = 1; i < n; i++)
        {
            for (int t = 0; t <= target; t++)
            {
                int notTake = 0 + prev[t];
                int take = INT_MAX;
                if (coins[i] <= t)
                {
                    take = 1 + curr[t - coins[i]];
                }

                curr[t] = min(take, notTake);
            }
            prev = curr;
        }

        if (prev[target] >= 1e9)
            return -1;

        return prev[target];
    }
};