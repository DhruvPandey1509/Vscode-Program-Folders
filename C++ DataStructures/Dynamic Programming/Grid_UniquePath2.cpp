#include "bits/stdc++.h"
using namespace std;

// recursion
int solve(vector<vector<int>> &v, int i, int j)
{
    if (i >= 0 and j >= 0 and v[i][j] == -1)
        return 0;
    if (i < 0 || j < 0)
        return 0;

    if (i == 0 and j == 0)
        return 1;

    return solve(v, i - 1, j) + solve(v, i, j - 1);
}

// Memoization
int solve1(vector<vector<int>> &v, vector<vector<int>> &dp, int i, int j)
{
    if (i >= 0 and j >= 0 and v[i][j] == -1)
        return 0;
    if (i < 0 || j < 0)
        return 0;

    if (i == 0 and j == 0)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    return dp[i][j] = solve(v, i - 1, j) + solve(v, i, j - 1);
}

// DP :- Tabulation
int solve2(vector<vector<int>> &v)
{
    int n = v.size();
    int m = v[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == -1)
                dp[i][j] = 0;
            else if (i == 0 and j == 0)
                dp[i][j] = 1;

            else
            {
                if (i > 0)
                    dp[i][j] += dp[i - 1][j];
                if (j > 0)
                    dp[i][j] += dp[i][j - 1];
            }
        }
    }

    return dp[n - 1][m - 1];
}

// Dp :- Tabulation(Bottom Up) + space Optimization
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
            if (v[i][j] == -1)
                curr[j] = 0;
            else if (i == 0 and j == 0)
                curr[j] = 1;

            else
            {
                if (i > 0)
                    curr[j] += prev[j];
                if (j > 0)
                    curr[j] += curr[j - 1];
            }
        }
        prev = curr;
    }

    return prev[m - 1];
}

int main()
{
    vector<vector<int>> v = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};

    int n = v.size();
    int m = v[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    cout << solve(v, n - 1, m - 1) << endl;
    cout << solve1(v, dp, n - 1, m - 1) << endl;
    cout << solve2(v) << endl;
    cout << solve3(v) << endl;

    return 0;
}