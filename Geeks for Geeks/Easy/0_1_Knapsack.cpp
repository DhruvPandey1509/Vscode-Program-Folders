#include "bits/stdc++.h"
using namespace std;

class Solution
{

public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int prices[], int N)
    {
        vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

        for (int n = 1; n <= N; n++)
        {
            for (int w = 1; w <= W; w++)
            {
                int inc = 0, exc = 0;
                if (wt[n - 1] <= w)
                {
                    inc = prices[n - 1] + dp[n - 1][w - wt[n - 1]];
                }
                exc = dp[n - 1][w];

                dp[n][w] = max(inc, exc);
            }
        }

        return dp[N][W];
    }
};