#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int maxNonAdjSum(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return arr[0];
    }

    vector<int> dp(n);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], arr[i] + dp[i - 2]);
    }

    return dp[n - 1];
}

int main()
{
    int arr[] = {6, 10, 12, 7, 9, 14};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << maxNonAdjSum(arr, n) << endl;
    return 0;
}