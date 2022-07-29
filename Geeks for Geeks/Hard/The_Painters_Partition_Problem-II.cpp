#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int feasible(int arr[], int n, int limit)
    {
        int sum = 0, painters = 1;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum > limit)
            {
                sum = arr[i];
                painters++;
            }
        }

        return painters;
    }
    long long minTime(int arr[], int n, int k)
    {
        long long lo = 0, hi = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > lo)
                lo = arr[i];
            hi += arr[i];
        }

        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            int painters = feasible(arr, n, mid);
            if (painters <= k)
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return lo;
    }
};