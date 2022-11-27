#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int res = 0;
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                long diff = (long)nums[i] - (long)nums[j];
                if (diff < INT_MIN or diff > INT_MAX)
                    continue;

                dp[i][diff]++;
                if (!dp[j].count(diff))
                    continue;

                res += dp[j][diff];
                dp[i][diff] += dp[j][diff];
            }
        }
        return res;
    }
};
