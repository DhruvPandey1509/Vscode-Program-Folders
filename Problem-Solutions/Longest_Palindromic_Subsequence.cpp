#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        string rev = s;
        reverse(rev.begin(), rev.end());

        vector<vector<int>> dp(s.size() + 1, vector<int>(rev.size() + 1, 0));
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= rev.size(); j++)
            {
                if (s[i - 1] == rev[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[s.size()][rev.size()];
    }
};
