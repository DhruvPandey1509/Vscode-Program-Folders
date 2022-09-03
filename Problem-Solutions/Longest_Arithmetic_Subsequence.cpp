#include "bits/stdc++.h"
using namespace std;

// Brute Force Approach
class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {

        int n = nums.size();
        if (n <= 2)
            return n;

        vector<unordered_map<int, int>> dp(n);
        int maxLen = 2;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int diff = nums[j] - nums[i];
                if (dp[i].find(diff) != dp[i].end())
                {
                    dp[j][diff] = dp[i][diff] + 1;
                }
                else
                {
                    dp[j][diff] = 2;
                }
                maxLen = max(maxLen, dp[j][diff]);
            }
        }

        return maxLen;
    }
};

// Optimized Solution
class Solution1
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {

        int n = nums.size();
        if (n <= 2)
            return n;

        vector<vector<int>> dp(n, vector<int>(1001, 1));
        int max_len = 0;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int diff = nums[j] - nums[i] + 500;
                dp[i][diff] = dp[j][diff] + 1;
                max_len = max(max_len, dp[i][diff]);
            }
        }

        return max_len;
    }
};