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
bool solve2(vector<int> &v, int sum)
{
    int n = v.size();

    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    dp[0][v[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= sum; j++)
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

    int res = INT_MAX;
    for (int i = 0; i <= sum / 2; i++)
    {
        if (dp[n - 1][i])
        {
            int s2 = sum - i;
            res = min(res, abs(i - s2));
        }
    }

    return res;
}
bool solve3(vector<int> &v, int sum)
{
    int n = v.size();
    vector<bool> prev(sum + 1, 0), curr(sum + 1, 0);
    prev[0] = curr[0] = 1;
    prev[v[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= sum; j++)
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

    int res = INT_MAX;
    for (int i = 0; i < sum / 2; i++)
    {
        if (prev[i])
        {
            int s2 = sum - i;
            res = min(res, abs(i - s2));
        }
    }

    return res;
}
int main()
{
    vector<int> v = {3, 2, 7, 1, 2, 6};
    int n = v.size();
    int sum = accumulate(v.begin(), v.end(), 0);
    int res = INT_MAX;
    for (int target = 0; target <= sum; target++)
    {
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        if (solve(v, target, n - 1))
        {
            int s1 = target;
            int s2 = abs(sum - target);
            res = min(res, abs(s1 - s2));
        }
        if (res == 0)
            break;
    }
    cout << res << endl;
    res = INT_MAX;
    for (int target = 0; target <= sum; target++)
    {
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        if (solve1(v, dp, target, n - 1))
        {
            int s1 = target;
            int s2 = abs(sum - target);
            res = min(res, abs(s1 - s2));
        }
        if (res == 0)
            break;
    }
    cout << res << endl;

    cout << solve2(v, sum) << endl;
    cout << solve3(v, sum) << endl;
    return 0;
}