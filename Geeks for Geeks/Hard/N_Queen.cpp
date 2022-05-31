#include "bits/stdc++.h"
using namespace std;

class Solution
{
    bool isSafe(vector<vector<int>> dp, int n, int x, int y)
    {
        for (int i = x - 1; i >= 0; i--)
        {
            if (dp[i][y] == 1)
                return false;
        }
        int row = x - 1;
        int col = y - 1;

        while (row >= 0 && col >= 0)
        {
            if (dp[row][col] == 1)
                return false;
            row--;
            col--;
        }
        row = x - 1;
        col = y + 1;

        while (row >= 0 && col < n)
        {
            if (dp[row][col] == 1)
                return false;
            row--;
            col++;
        }

        return true;
    }

    void solve(vector<vector<int>> dp, vector<vector<int>> &res, vector<int> temp, int n, int x)
    {
        if (x == n)
        {
            res.push_back(temp);
            return;
        }
        for (int y = 0; y < n; y++)
        {
            if (isSafe(dp, n, x, y))
            {
                dp[x][y] = 1;
                temp.push_back(y + 1);
                solve(dp, res, temp, n, x + 1);
                dp[x][y] = 0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> nQueen(int n)
    {
        // code here
        vector<vector<int>> res;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> temp;
        solve(dp, res, temp, n, 0);

        return res;
    }
};