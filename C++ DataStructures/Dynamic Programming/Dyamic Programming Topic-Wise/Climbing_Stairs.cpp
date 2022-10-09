#include "bits/stdc++.h"
using namespace std;

//Recursion T.C = O(2^n)   S.C = O(n)
int solve(int i)
{
    if (i == 0)
        return 1;
    if (i < 0)
        return 0;

    return solve(i - 1) + solve(i - 2);
}

// Memoization
// T.C = O(n)  S.C = O(n) + O(n);
int solve(vector<int> &dp, int i)
{
    if (i == 0)
        return 1;
    if (i < 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    return dp[i] = solve(dp, i - 1) + solve(dp, i - 2);
}

// Tabulation T.C = O(n)  S.C = O(n)
int tabulation(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// Space Optimization  T.C = O(n)  S.C = O(1) constant
int spaceOptimization(int n)
{
    int a = 1;
    int b = 1;
    int c = 0;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << solve(n) << endl;
    cout << solve(dp, n) << endl;
    cout << tabulation(n) << endl;
    cout << spaceOptimization(n) << endl;
    return 0;
}