#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int combination(vector<int> &nums, vector<int> &dp, int target)
    {
        if (target == 0)
            return 1;
        if (target < 0)
            return 0;
        if (dp[target] != -1)
            return dp[target];
        int t = 0;
        for (auto i : nums)
        {
            if (target - i >= 0)
            {
                t += combination(nums, dp, target - i);
            }
        }

        return dp[target] = t;
    }
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1, -1);
        return combination(nums, dp, target);
    }
};