#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int dp[21][21];
    int solve(vector<int> &nums, int st, int en)
    {
        if (st > en)
            return 0;
        if (st == en)
            return nums[st];

        if (dp[st][en] != -1)
            return dp[st][en];

        // player 2 plays optimally so the player 1 will get the minimum out of what is left
        int a = nums[st] + min(solve(nums, st + 2, en), solve(nums, st + 1, en - 1));
        int b = nums[en] + min(solve(nums, st, en - 2), solve(nums, st + 1, en - 1));
        return dp[st][en] = max(a, b);
    }

    bool PredictTheWinner(vector<int> &nums)
    {

        // if number of elements in the nums is even then player 1 will always win sine he can chose whether to choose even position elements or odd that maximize his score
        int n = nums.size();
        if (n % 2 == 0)
            return true;
        memset(dp, -1, sizeof(dp));
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int res = solve(nums, 0, n - 1);
        return res >= sum - res;
    }
};