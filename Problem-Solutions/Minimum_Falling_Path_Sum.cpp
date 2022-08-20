#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int res = INT_MAX;

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            dp[0][i] = mat[0][i];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int up = mat[i][j] + dp[i - 1][j];
                int left = INT_MAX, right = INT_MAX;

                if (j - 1 >= 0)
                {
                    left = mat[i][j] + dp[i - 1][j - 1];
                }
                if (j + 1 < n)
                {
                    right = mat[i][j] + dp[i - 1][j + 1];
                }
                dp[i][j] = min(up, min(left, right));
            }
        }

        res = *min_element(dp[n - 1].begin(), dp[n - 1].end());
        return res;
    }
};