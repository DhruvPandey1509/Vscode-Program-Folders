#include "bits/stdc++.h"
using namespace std;

int solve(vector<vector<int>> &v, int i, int j, int n)
{
    if (i == n - 1)
        return v[i][j];

    int down = solve(v, i + 1, j, n);
    int diag = solve(v, i + 1, j + 1, n);

    return min(down, diag) + v[i][j];
}
int solve1(vector<vector<int>> &v, vector<vector<int>> &dp, int i, int j, int n)
{
    if (i == n - 1)
        return v[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];

    int down = solve(v, i + 1, j, n);
    int diag = solve(v, i + 1, j + 1, n);

    return dp[i][j] = min(down, diag) + v[i][j];
}
int solve2(vector<vector<int>> &v)
{
    int n = v.size();
    int m = v[n - 1].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (i == 0 and j == 0)
                dp[i][j] = v[i][j];
            else
            {
                int down = 1e8;
                int diag = 1e8;

                if (i > 0)
                    down = v[i - 1][j];
                if (j > 0 and i > 0)
                    diag = v[i - 1][j - 1];

                dp[i][j] = min(down, diag) + v[i][j];
            }
        }
    }

    return dp[n - 1][m - 1];
}

int main()
{
    vector<vector<int>> v = {
        {1},
        {2, 3},
        {3, 6, 7},
        {8, 9, 6, 11}};

    int n = v.size();
    int m = v[n - 1].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << solve(v, 0, 0, n) << endl;
    cout << solve1(v, dp, 0, 0, n) << endl;
    cout << solve2(v) << endl;
    return 0;
}