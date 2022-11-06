#include "bits/stdc++.h"
using namespace std;
// recursion
int solve(vector<vector<int>> &v, int r, int c1, int c2, int n, int m)
{
    if (c1 < 0 || c1 >= m || c2 < 0 || c2 >= m)
        return -1e7;
    if (r == n - 1)
    {
        if (c1 == c2)
        {
            return v[r][c1];
        }
        else
        {
            return v[r][c1] + v[r][c2];
        }
    }

    int res = 0;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (c1 == c2)
                res = max(res, v[r][c1] + solve(v, r + 1, c1 + i, c2 + j, n, m));
            else
                res = max(res, v[r][c1] + v[r][c2] + solve(v, r + 1, c1 + i, c2 + j, n, m));
        }
    }
}

// dp Memoisation (Top Down)
int solve1(vector<vector<int>> &v, vector<vector<vector<int>>> &dp, int r, int c1, int c2, int n, int m)
{
    if (c1 < 0 || c1 >= m || c2 < 0 || c2 >= m)
        return -1e7;
    if (r == n - 1)
    {
        if (c1 == c2)
        {
            return v[r][c1];
        }
        else
        {
            return v[r][c1] + v[r][c2];
        }
    }
    if (dp[r][c1][c2] != INT_MIN)
        return dp[r][c1][c2];

    int res = 0;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (c1 == c2)
                res = max(res, v[r][c1] + solve1(v, dp, r + 1, c1 + i, c2 + j, n, m));
            else
                res = max(res, v[r][c1] + v[r][c2] + solve1(v, dp, r + 1, c1 + i, c2 + j, n, m));
        }
    }

    return dp[r][c1][c2] = res;
}

// Dp Tabulation (Bottom Up)
int solve2(vector<vector<int>> v)
{
    int r = v.size();
    int c = v[0].size();
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));

    for (int j1 = 0; j1 < c; j1++)
    {
        for (int j2 = 0; j2 < c; j2++)
        {
            if (j1 == j2)
                dp[r - 1][j1][j2] = v[r - 1][j1];
            else
                dp[r - 1][j1][j2] = v[r - 1][j1] + v[r - 1][j2];
        }
    }

    for (int i = r - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {
                int res = INT_MIN;
                for (int dj1 = -1; dj1 < 2; dj1++)
                {
                    for (int dj2 = -1; dj2 < 2; dj2++)
                    {
                        int val;
                        if (j1 == j2)
                            val = v[i][j1];
                        else
                            val = v[i][j1] + v[i][j2];

                        if (j1 + dj1 >= 0 and j1 + dj1 < c and j2 + dj2 >= 0 and j2 + dj2 < c)
                        {
                            val += dp[i + 1][j1 + dj1][j2 + dj2];
                        }
                        else
                        {
                            val += -1e8;
                        }

                        res = max(res, val);
                    }
                }

                dp[i][j1][j2] = res;
            }
        }
    }

    return dp[0][0][c - 1];
}

// DP Tabulation + Space Optimisation
int solve3(vector<vector<int>> v)
{
    int r = v.size();
    int c = v[0].size();
    vector<vector<int>> prev(c, vector<int>(c, 0));
    vector<vector<int>> curr(c, vector<int>(c, 0));

    for (int j1 = 0; j1 < c; j1++)
    {
        for (int j2 = 0; j2 < c; j2++)
        {
            if (j1 == j2)
                prev[j1][j2] = v[r - 1][j1];
            else
                prev[j1][j2] = v[r - 1][j1] + v[r - 1][j2];
        }
    }

    for (int i = r - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {
                int res = INT_MIN;
                for (int dj1 = -1; dj1 < 2; dj1++)
                {
                    for (int dj2 = -1; dj2 < 2; dj2++)
                    {
                        int val;
                        if (j1 == j2)
                            val = v[i][j1];
                        else
                            val = v[i][j1] + v[i][j2];

                        if (j1 + dj1 >= 0 and j1 + dj1 < c and j2 + dj2 >= 0 and j2 + dj2 < c)
                        {
                            val += prev[j1 + dj1][j2 + dj2];
                        }
                        else
                        {
                            val += -1e8;
                        }

                        res = max(res, val);
                    }
                }

                curr[j1][j2] = res;
            }
        }

        prev = curr;
    }

    return prev[0][c - 1];
}

int main()
{
    vector<vector<int>> v = {
        {2, 3, 1, 2},
        {3, 4, 2, 4},
        {5, 6, 3, 5},
    };
    int n = v.size();
    int m = v[0].size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, INT_MIN)));
    cout << solve(v, 0, 0, m - 1, n, m) << endl;
    cout << solve1(v, dp, 0, 0, m - 1, n, m) << endl;
    cout << solve2(v) << endl;
    cout << solve3(v) << endl;

    return 0;
}