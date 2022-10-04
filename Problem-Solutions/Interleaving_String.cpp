#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3, vector<vector<int>> &dp, int i, int j)
    {
        if (s1.size() == 0 && s2.size() == 0 && s3.size() == 0)
            return true;

        bool first = false, second = false;
        if (dp[i][j] == -1)
        {
            if (s1.size() && s1[0] == s3[0])
            {
                first = isInterleave(s1.substr(1), s2, s3.substr(1), dp, i + 1, j);
                dp[i][j] = first;
            }
            if (first)
                return true;
            if (s2.size() && s2[0] == s3[0])
            {
                second = isInterleave(s1, s2.substr(1), s3.substr(1), dp, i, j + 1);
                dp[i][j] = second;
            }
        }
        return dp[i][j] == 1;
    }

    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.size() + s2.size() != s3.size())
            return false;
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return isInterleave(s1, s2, s3, dp, 0, 0);
    }
};