#include "bits/stdc++.h"
using namespace std;

// Recursion
int solve(vector<vector<int>> &v, int invalidIdx, int currLevel)
{
    if (currLevel < 0)
        return 0;
    int res = INT_MIN;

    for (int i = 0; i < v[currLevel].size(); i++)
    {
        if (i == invalidIdx)
            continue;
        res = max(res, solve(v, i, currLevel - 1) + v[currLevel][i]);
    }
    return res;
}

// DP :- Top Down
int solve1(vector<vector<int>> &v, vector<vector<int>> dp, int day, int last)
{
    if (day == 0)
    {
        int res = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i == last)
                continue;

            res = max(res, v[0][i]);
        }
        return res;
    }

    if (dp[day][last] != -1)
    {
        return dp[day][last];
    }
    int res = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i == last)
            continue;

        res = max(res, v[day][i] + solve1(v, dp, day - 1, i));
    }

    return dp[day][last] = res;
}

// DP :- Tabulation(Bottom Up)
int solve2(vector<vector<int>> &v, int n)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));

    dp[0][0] = max(v[0][1], v[0][2]);
    dp[0][1] = max(v[0][0], v[0][2]);
    dp[0][2] = max(v[0][0], v[0][1]);
    dp[0][3] = max({v[0][0], v[0][1], v[0][2]});

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int i = 0; i < 3; i++)
            {
                if (i == last)
                    continue;

                dp[day][last] = max(dp[day][last], v[day][i] + dp[day - 1][i]);
            }
        }
    }

    return dp[n - 1][3];
}
// DP :- Tabulation(Bottom Up) + Space Optimization
int solve3(vector<vector<int>> &v, int n)
{
    vector<int> prev(4, 0);

    prev[0] = max(v[0][1], v[0][2]);
    prev[1] = max(v[0][0], v[0][2]);
    prev[2] = max(v[0][0], v[0][1]);
    prev[3] = max({v[0][0], v[0][1], v[0][2]});

    for (int day = 1; day < n; day++)
    {
        vector<int> curr(4, 0);
        for (int last = 0; last < 4; last++)
        {
            curr[last] = 0;
            for (int i = 0; i < 3; i++)
            {
                if (i == last)
                    continue;

                curr[last] = max(curr[last], v[day][i] + curr[i]);
            }
        }
        prev = curr;
    }

    return prev[3];
}

int main()
{
    vector<vector<int>> v = {
        {10, 50, 1},
        {5, 100, 110},
        {50, 10, 10},
        {100, 20, 50}};
    int currLvl = v.size();
    int col = v[0].size();

    vector<vector<int>> dp(currLvl, vector<int>(4, -1));
    cout << solve(v, -1, currLvl - 1) << endl;
    cout << solve1(v, dp, currLvl - 1, 3) << endl;
    cout << solve2(v, currLvl) << endl;
    cout << solve3(v, currLvl) << endl;

    return 0;
}