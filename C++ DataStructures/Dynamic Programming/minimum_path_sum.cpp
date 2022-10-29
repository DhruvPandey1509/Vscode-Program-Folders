#include "bits/stdc++.h"
using namespace std;

// Recursion
int solve(vector<vector<int>> &v, int i, int j)
{
    if (i == 0 and j == 0)
        return v[i][j];
    if (i < 0 || j < 0)
        return 1e8;

    int left = solve(v, i - 1, j) + v[i][j];
    int up = solve(v, i, j - 1) + v[i][j];

    return min(up, left);
}
// DP :- Memoization (Top Down)
int solve1(vector<vector<int>> &v, vector<vector<int>> &dp, int i, int j)
{
    if (i == 0 and j == 0)
        return v[i][j];
    if (i < 0 || j < 0)
        return 1e8;
    if (dp[i][j] != -1)
        return dp[i][j];
    int left = solve(v, i - 1, j) + v[i][j];
    int up = solve(v, i, j - 1) + v[i][j];

    return dp[i][j] = min(up, left);
}

// DP :- Tabulation(Bottom Up)
int solve2(vector<vector<int>> &v)
{
    int n = v.size();
    int m = v[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 and j == 0)
                dp[i][j] = v[i][j];
            else
            {
                int up = 1e8;
                int left = 1e8;
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];

                dp[i][j] = min(up, left) + v[i][j];
            }
        }
    }
    return dp[n - 1][m - 1];
}
// DP :- Tabulation(Bottom Up) + Space Optimization
int solve3(vector<vector<int>> &v)
{
    int n = v.size();
    int m = v[0].size();
    vector<int> prev(m, 0);

    for (int i = 0; i < n; i++)
    {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 and j == 0)
                curr[j] = v[i][j];
            else
            {
                int up = 1e8;
                int left = 1e8;
                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = curr[j - 1];

                curr[j] = min(up, left) + v[i][j];
            }
        }
        prev = curr;
    }
    return prev[m - 1];
}

int main()
{
    vector<vector<int>> v = {
        {5, 9, 6},
        {11, 5, 2}};

    int n = v.size();
    int m = v[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << solve(v, n - 1, m - 1) << endl;
    cout << solve1(v, dp, n - 1, m - 1) << endl;
    cout << solve2(v) << endl;
    cout << solve3(v) << endl;

    return 0;
}