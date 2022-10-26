#include "bits/stdc++.h"
using namespace std;

// recursion
int solve(int i, int j)
{
    // base cases
    if (i == 0 and j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    return solve(i - 1, j) + solve(i, j - 1);
}

// DP Memoization(Top down)
int solve1(vector<vector<int>> dp, int i, int j)
{
    // base cases
    if (i == 0 and j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    return dp[i][j] = solve1(dp, i - 1, j) + solve1(dp, i, j - 1);
}

// DP Bottom Up (Tabulation)
int solve2(int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 and j == 0)
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

    return dp[n][m];
}

// DP :- Tabulation + Space Optimized
int solve3(int n, int m)
{
    vector<int> prev(m + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        vector<int> curr(m + 1, 0);
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 and j == 0)
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

    return prev[m];
}

int main()
{
    int n = 4, m = 4;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << solve(n, m) << endl;
    cout << solve1(dp, n, m) << endl;
    cout << solve2(n, m) << endl;
    cout << solve3(n, m) << endl;
    return 0;
}