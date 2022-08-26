#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    long long dp[2][100001];
    long long util(int i, vector<int> &nums, bool flag)
    {

        if (i >= nums.size())
            return 0;
        if (dp[flag][i] != -1)
            return dp[flag][i];
        long long curr = (flag ? nums[i] : -1 * nums[i]);
        return dp[flag][i] = max(curr + util(i + 1, nums, !flag), util(i + 1, nums, flag));
    }
    long long maxAlternatingSum(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        return util(0, nums, true);
    }
};
