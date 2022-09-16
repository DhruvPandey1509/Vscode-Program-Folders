#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums, vector<int> &m, vector<vector<int>> &dp, int i, int s, int e)
    {
        if (i == m.size())
            return 0;
        if (dp[i][s] != INT_MIN)
            return dp[i][s];

        int left = m[i] * nums[s] + solve(nums, m, dp, i + 1, s + 1, e);
        int right = m[i] * nums[e] + solve(nums, m, dp, i + 1, s, e - 1);

        return dp[i][s] = max(left, right);
    }
    int maximumScore(vector<int> &nums, vector<int> &m)
    {
        vector<vector<int>> dp(1001, vector<int>(1001, INT_MIN));
        int n = nums.size();
        return solve(nums, m, dp, 0, 0, n - 1);
    }
};

