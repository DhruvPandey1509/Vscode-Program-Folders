#include "bits/stdc++.h"
using namespace std;

long long maxArea(long long a[], int len)
{
    long long res = 0;
    int l = 0;
    int r = len - 1;
    while (l < r)
    {
        res = max(res, (r - l) * min(a[l], a[r]));
        if (a[l] < a[r])
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    return res;
}