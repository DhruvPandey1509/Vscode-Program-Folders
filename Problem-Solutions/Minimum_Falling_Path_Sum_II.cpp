#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int solve(vector<vector<int>> &v, vector<vector<int>> &dp, int i, int j)
    {
        if (j < 0 || j >= v.size())
            return 1e8;
        if (i == 0)
            return v[i][j];

        if (dp[i][j] != -100)
            return dp[i][j];

        int res = INT_MAX;
        for (int k = 0; k < v.size(); k++)
        {
            if (j == k)
                continue;

            res = min(res, v[i][j] + solve(v, dp, i - 1, k));
        }

        return dp[i][j] = res;
    }
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> prev(n, 0);
        for (int i = 0; i < n; i++)
        {
            prev[i] = grid[0][i];
        }

        int res = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++)
            {
                int val = INT_MAX;
                for (int k = 0; k < n; k++)
                {
                    if (j == k)
                        continue;
                    val = min(val, grid[i][j] + prev[k]);
                }

                curr[j] = val;
            }
            prev = curr;
        }
        for (int i = 0; i < n; i++)
        {
            res = min(res, prev[i]);
        }
        return res;
    }
};