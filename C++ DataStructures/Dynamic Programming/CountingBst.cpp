#include <iostream>
#include <vector>
using namespace std;

// (Recurrsive)
// Time Complexity :- exponential
int countBst(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = countBst(i - 1);
        int y = countBst(n - i);
        ans += x * y;
    }

    return ans;
}

// Top Down Approach (Recursive  -  memoization)
// Time Complexity :-  O(n^2)
int countBstTD(int n, vector<int> dp)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    if (dp[n] != 0)
    {
        return dp[n];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = countBstTD(i - 1, dp);
        int y = countBstTD(n - i, dp);
        ans += x * y;
    }

    return dp[n] = ans;
}
// Bottom-Up Approach
int countBstBU(int n)
{
    // vector<int> dp(n + 1, 0);
    int *dp = new int[n + 1]{0}; //DMA initialising with 0
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] += (dp[j - 1] * dp[i - j]);
        }
    }

    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    cout << countBst(n) << endl;
    cout << countBstTD(n, dp) << endl;
    cout << countBstBU(n) << endl;

    return 0;
}