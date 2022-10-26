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
// recursive way
int func(int *a, int idx)
{
    if (idx == 0)
        return a[0];
    if (idx < 0)
        return 0;

    int pick = a[idx] + func(a, idx - 2);
    int not_pick = func(a, idx - 1);
    return max(pick, not_pick);
}
// top down (memoization)
int func2(vector<int> &dp, int a[], int idx)
{
    if (idx == 0)
        return a[0];
    if (idx < 0)
        return 0;
    if (dp[idx] != INT_MIN)
        return dp[idx];

    return dp[idx] = max(func2(dp, a, idx - 1), a[idx] + func2(dp, a, idx));
}
// space optimized :- Same as tabulation just with O(1) space
int func(int a[], int n)
{
    int prev2 = a[0];
    int prev = max(a[0], a[1]);
    int curr;

    for (int i = 2; i < n; i++)
    {
        curr = max(prev, prev2 + a[i]);
        prev2 = prev;
        prev = curr;
    }

    return curr;
}
int main()
{
    int arr[] = {6, 10, 12, 7, 9, 14};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << maxNonAdjSum(arr, n) << endl;
    return 0;
}