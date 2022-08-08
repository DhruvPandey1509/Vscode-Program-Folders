#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 1;
        int n = nums.size();
        vector<int> dp(n + 1, 1);

        int res = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }

                res = max(res, dp[i]);
            }
        }
        return res;
    }
};