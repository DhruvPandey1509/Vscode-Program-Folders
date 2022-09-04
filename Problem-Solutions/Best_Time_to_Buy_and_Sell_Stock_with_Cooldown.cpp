#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int solve(vector<int> &prices, int i, bool buy, vector<vector<int>> &dp)
    {
        if (i >= prices.size())
            return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];

        if (buy)
        { // can buy
            // maximum of if we buy stock at current prices or we do not buy stock at current prices
            return dp[i][buy] = max(-prices[i] + solve(prices, i + 1, !buy, dp), solve(prices, i + 1, buy, dp));
        }
        else
        {
            // maximum of if we sell stock at current prices or we do not sell stock at current prices
            return dp[i][buy] = max(prices[i] + solve(prices, i + 2, !buy, dp), solve(prices, i + 1, buy, dp));
        }
    }
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solve(prices, 0, 1, dp);
    }
};
