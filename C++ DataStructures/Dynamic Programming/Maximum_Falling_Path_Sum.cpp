#include "bits/stdc++.h"
using namespace std;
// Recursion
int solve(vector<vector<int>> &v, int r, int c)
{
    if (c < 0 || c >= v[0].size())
        return -1e8;
    else if (r == 0)
        return v[0][c];

    int left = solve(v, r - 1, c - 1);
    int down = solve(v, r - 1, c);
    int right = solve(v, r - 1, c + 1);

    return max(left, max(right, down)) + v[r][c];
}
// Memoization DP
int solve1(vector<vector<int>> &v, vector<vector<int>> &dp, int r, int c)
{
    if (c < 0 || c >= v[0].size())
        return -1e8;
    else if (r == 0)
        return v[0][c];
    if (dp[r][c] != INT_MIN)
    {
        return dp[r][c];
    }
    int left = solve(v, r - 1, c - 1);
    int down = solve(v, r - 1, c);
    int right = solve(v, r - 1, c + 1);
    return dp[r][c] = max(left, max(right, down)) + v[r][c];
}
// Tabulation DP
int solve2(vector<vector<int>> &v)
{
    int n = v.size();
    int m = v[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = v[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = v[i][j] + dp[i - 1][j];
            int ld = v[i][j];
            if (j - 1 >= 0)
                ld += dp[i - 1][j - 1];
            int rd = v[i][j];
            if (j + 1 < m)
                rd += v[i - 1][j + 1];
            dp[i][j] = max(u, max(ld, rd));
        }
    }

    int res = -1e8;
    for (int j = 0; j < m; j++)
    {
        res = max(res, dp[n - 1][j]);
    }
    return res;
}
// Tabulation + Space Optimization DP
int solve3(vector<vector<int>> &v)
{
    int n = v.size();
    int m = v[0].size();

    vector<int> prev(m, 0);
    for (int j = 0; j < m; j++)
    {
        prev[j] = v[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++)
        {
            int u = v[i][j] + prev[j];
            int ld = v[i][j];
            if (j - 1 >= 0)
                ld += prev[j - 1];
            int rd = v[i][j];
            if (j + 1 < m)
                rd += prev[j + 1];
            curr[j] = max(u, max(ld, rd));
        }
        prev = curr;
    }

    int res = -1e8;
    for (int j = 0; j < m; j++)
    {
        res = max(res, prev[j]);
    }
    return res;
}

int main()
{
    vector<vector<int>> v = {
        {1, 2, 10, 4},
        {100, 3, 2, 1},
        {1, 1, 20, 2},
        {1, 2, 2, 1}};

    int n = v.size();
    int m = v[0].size();

    int res = -1e8;
    int res1 = -1e8;
    for (int j = 0; j < m; j++)
    {
        res = max(res, solve(v, n - 1, j));
    }
    vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
    for (int j = 0; j < m; j++)
    {
        res1 = max(res1, solve1(v, dp, n - 1, j));
    }
    cout << res << endl;
    cout << res1 << endl;
    cout << solve2(v) << endl;
    cout << solve3(v) << endl;
    return 0;
}