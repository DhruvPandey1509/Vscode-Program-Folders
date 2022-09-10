#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {

        if (k == 0)
            return 0;

        // dp[k][0] = min cost you need to spend at most k transactions
        // dp[k][1] = max profit you can achieve at most k transactions

        vector<vector<int>> dp(k + 1, vector<int>(2));
        for (int i = 0; i <= k; i++)
            dp[i][0] = INT_MAX;

        for (auto p : prices)
        {
            for (int i = 1; i <= k; i++)
            {
                // price - dp[i - 1][1] is how much you need to spend
                // i.e use the profit you earned from previous transaction to buy the stock
                // we want to minimize it
                cout << "Before" << endl;
                cout << "dp[" << i << "][0] : " << dp[i][0] << "  "
                     << "dp[" << i << "][1] : " << dp[i][1] << endl;
                dp[i][0] = min(dp[i][0], p - dp[i - 1][1]);

                // price - dp[i][0] is how much you can achieve from previous min cost
                // we want to maximize it
                dp[i][1] = max(dp[i][1], p - dp[i][0]);
                cout << "After" << endl;
                cout << "dp[" << i << "][0] : " << dp[i][0] << "  "
                     << "dp[" << i << "][1] : " << dp[i][1] << endl;
            }
        }

        return dp[k][1];
    }
};