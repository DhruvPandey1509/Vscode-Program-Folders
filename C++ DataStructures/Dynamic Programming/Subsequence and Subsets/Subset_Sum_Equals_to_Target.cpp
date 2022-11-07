#include "bits/stdc++.h"
using namespace std;
bool solve(vector<int> &v, int target, int idx)
{
    if (target == 0)
        return true;
    if (idx == 0)
        return v[0] == target;

    bool notTake = solve(v, target, idx - 1);
    bool take = false;
    if (v[idx] <= target)
    {
        take = solve(v, target - v[idx], idx - 1);
    }
    return take || notTake;
}

bool solve1(vector<int> &v, vector<vector<int>> &dp, int target, int idx)
{
    if (target == 0)
        return true;
    if (idx == 0)
        return v[0] == target;
    if (dp[idx][target] != -1)
        return dp[idx][target];
    bool notTake = solve1(v, dp, target, idx - 1);
    bool take = false;
    if (v[idx] <= target)
    {
        take = solve1(v, dp, target - v[idx], idx - 1);
    }
    return dp[idx][target] = take || notTake;
}
bool solve2(vector<int> &v, int target)
{
    int n = v.size();
    vector<vector<bool>> dp(n, vector<bool>(target + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    dp[0][v[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            bool notTake = dp[i - 1][j];
            bool take = false;
            if (v[i] <= j)
            {
                take = dp[i - 1][j - v[i]];
            }

            dp[i][j] = take || notTake;
        }
    }

    return dp[n - 1][target];
}
bool solve3(vector<int> &v, int target)
{
    int n = v.size();
    vector<bool> prev(target + 1, 0), curr(target + 1, 0);
    prev[0] = curr[0] = 1;
    prev[v[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            bool notTake = prev[j];
            bool take = false;
            if (v[i] <= j)
            {
                take = prev[j - v[i]];
            }

            curr[j] = take || notTake;
        }
        prev = curr;
    }

    return prev[target];
}
int main()
{
    vector<int> v = {3, 2, 7, 1, 2, 5};
    int target = 10;
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    cout << solve(v, target, n - 1) << endl;
    cout << solve1(v, dp, target, n - 1) << endl;
    cout << solve2(v, target) << endl;
    cout << solve3(v, target) << endl;
    return 0;
}