#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int longestIdealString(string s, int k)
    {

        vector<int> dp(26, 0);
        int res = 1;

        for (char c : s)
        {
            int i = c - 'a';
            dp[i] = dp[i] + 1;

            // j is starting from the lowest char value for current char for which the condition that the difference in character should be  <= k holds true in the string
            // it goes upto the min of maximum char value present in the string for current character value greater than it.

            for (int j = max(0, i - k); j <= min(25, i + k); j++)
            {
                if (j != i) // to make sure we do not take itself into account
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            res = max(res, dp[i]);
        }

        return res;
    }
};
