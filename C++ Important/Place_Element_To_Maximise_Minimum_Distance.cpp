#include "bits/stdc++.h"
using namespace std;

bool isFeasible(int arr[], int mid, int n, int k)
{
    int pos = arr[0], elements = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - pos >= mid)
        {
            pos = arr[i];
            elements++;
            if (elements == k)
            {
                return true;
            }
        }
    }

    return false;
}

int largestMinDistance(int arr[], int n, int k)
{
    sort(arr, arr + n);

    int res = -1;
    int left = 1, right = arr[n - 1];

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (isFeasible(arr, mid, n, k))
        {
            res = max(res, mid);
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    return res;
}

int main()
{
    int arr[] = {1, 2, 5, 7, 11, 12};
    int n = 6;
    int k = 3;

    cout << largestMinDistance(arr, n, k) << endl;

    return 0;
}
