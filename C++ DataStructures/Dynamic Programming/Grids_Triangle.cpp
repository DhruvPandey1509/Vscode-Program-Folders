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
    for (int j = 0; j < m; j++)
    {
        dp[n - 1][j] = v[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = dp[i + 1][j];
            int diag = dp[i + 1][j + 1];
            dp[i][j] = min(down, diag) + v[i][j];
        }
    }

    return dp[0][0];
}

int solve3(vector<vector<int>> &v)
{
    int n = v.size();
    int m = v[n - 1].size();

    vector<int> front(n, 0), curr(n, 0);

    for(int j = 0; j < m; j++)
    {
        front[j] = v[n-1][j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = front[j];
            int diag = front[j + 1];
            curr[j] = min(down, diag) + v[i][j];
        }
        front = curr;
    }
    return front[0];
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
    cout << solve3(v) << endl;
    return 0;
}