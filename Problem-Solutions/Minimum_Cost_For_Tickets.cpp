#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &cost)
    {
        int lastDay = days.back();
        vector<int> dp(lastDay + 1);
        dp[0] = 0;

        for (int i = 1, j = 0; i <= lastDay; i++)
        {
            if (i == days[j])
            {
                j++;
                dp[i] = min({cost[0] + dp[i - 1], cost[1] + dp[i - min(i, 7)], cost[2] + dp[i - min(i, 30)]});
            }
            else
            {
                dp[i] = dp[i - 1];
            }
        }

        return dp[lastDay];
    }
};
