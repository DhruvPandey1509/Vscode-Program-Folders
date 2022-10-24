#include "bits/stdc++.h"
using namespace std;

// Recursion
int solve(vector<int> &v, int i)
{
    if (i == 0)
    {
        return 0;
    }

    int oneJump = solve(v, i - 1) + abs(v[i] - v[i - 1]);
    int twoJump = INT_MAX;
    if (i > 1)
    {
        twoJump = solve(v, i - 2) + abs(v[i] - v[i - 2]);
    }

    return min(oneJump, twoJump);
}
int main()
{
    vector<int> v = {10, 200, 100, 10};
    int n = v.size();
    vector<int> dp(n, -1);
    cout << solve(v, dp, n - 1) << endl;
    cout << dp[n - 1] << endl;
    return 0;
}

// Dynamic Programming :- top down
int solve(vector<int> &v, vector<int> &dp, int i)
{
    if (i == 0)
    {
        return 0;
    }
    if (dp[i] != -1)
        return dp[i];
    int oneJump = solve(v, dp, i - 1) + abs(v[i] - v[i - 1]);
    int twoJump = INT_MAX;
    if (i > 1)
    {
        twoJump = solve(v, dp, i - 2) + abs(v[i] - v[i - 2]);
    }

    return dp[i] = min(oneJump, twoJump);
}
int main()
{
    vector<int> v = {10, 200, 100, 10};
    int n = v.size();
    vector<int> dp(n, -1);
    cout << solve(v, dp, n - 1) << endl;
    cout << dp[n - 1] << endl;
    return 0;
}

// Tabulation :- Optimize
int main()
{
    vector<int> v = {10, 200, 100, 10};
    int n = v.size();
    vector<int> dp(n, 0);
    for (int i = 1; i < n; i++)
    {
        int oneJump = dp[i - 1] + abs(v[i] - v[i - 1]);
        int twoJump = 1e8;
        if (i > 1)
            twoJump = dp[i - 2] + abs(v[i] - v[i - 2]);

        dp[i] = min(oneJump, twoJump);
    }
    cout << dp[n - 1] << endl;
    return 0;
}

// Tabulation :- Space Optimized
int main()
{
    vector<int> v = {10, 20, 30, 10};
    int n = v.size();
    int one = 0;
    int two = 0;
    int curr = 0;

    for (int i = 1; i < n; i++)
    {
        int oneJump = one + abs(v[i] - v[i - 1]);
        int twoJump = INT_MAX;
        if (i > 1)
            twoJump = two + abs(v[i] - v[i - 2]);
        curr = min(oneJump, twoJump);
        two = one;
        one = curr;
    }
    cout << curr << endl;
    return 0;
}