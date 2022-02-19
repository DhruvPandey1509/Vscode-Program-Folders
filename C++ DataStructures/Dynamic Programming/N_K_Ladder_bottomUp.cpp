#include <iostream>
using namespace std;

int countWays(int n, int k, int dp[])
{
    dp[0] = 1;
    int t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i-j >= 0)
            {
                dp[i] += dp[i - j];
            }
        }
    }

    return dp[n];
}

int main()
{
    int n, k;
    cin >> n >> k;

    int dp[100] = {0};

    cout << countWays(n, k, dp) << endl;

    return 0;
}