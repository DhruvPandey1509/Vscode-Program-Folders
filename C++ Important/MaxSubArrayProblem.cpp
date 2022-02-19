/*
For a given array and integers a and X, find the maximum sum subarray of size a and having sum
less than X.
*/

#include <iostream>
using namespace std;

int maxSum(int *a, int n, int k, int x)
{
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        sum += a[i];
    }
    if (sum < x)
    {
        ans = sum;
    }
    for (int i = k; i < n; i++)
    {
        sum = sum + a[i] - a[i - k];
        if (sum < x)
        {
            ans = max(sum, ans);
        }
    }

    return ans;
}

int main()
{
    int a[] = {7, 5, 4, 6, 8, 9};
    int k = 3, x = 20;

    cout << maxSum(a, 6, k, x) << endl;

    return 0;
}