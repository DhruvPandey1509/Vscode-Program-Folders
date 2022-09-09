#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n);
        int mx = arr[0];
        for (int i = 0; i < k; i++)
        {
            mx = max(arr[i], mx);
            dp[i] = (mx * (i + 1));
        }
        for (int i = k; i < n; i++)
        {
            dp[i] = arr[i] + dp[i - 1];
            mx = arr[i];
            // check if a partition can result into the maximum sum
            for (int j = i - 1; j > i - k; j--)
            {
                mx = max(mx, arr[j]);
                dp[i] = max(dp[i], dp[j - 1] + (i - j + 1) * mx);
            }
        }
        return dp[n - 1];
    }
};
