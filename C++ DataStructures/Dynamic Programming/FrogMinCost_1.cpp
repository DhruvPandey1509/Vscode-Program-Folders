#include <iostream>
#include <vector>
using namespace std;

int minCost(int h[], int n)
{
    if (n == 0 || n == 1)
    {
        return 0;
    }

    vector<int> dp(n, 0);
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);

    for (int i = 2; i < n; i++)
    {
        int op1 = abs(h[i] - h[i - 1]) + dp[i - 1]; //jump gap of 1
        int op2 = abs(h[i] - h[i - 2]) + dp[i - 2]; //jump gap og 2

        dp[i] = min(op1, op2);
    }

    return dp[n - 1];
}

int main()
{
    int h[] = {30, 10, 60, 10, 60, 50};
    int n = sizeof(h) / sizeof(h[0]);

    cout << minCost(h, n) << endl;

    return 0;
}