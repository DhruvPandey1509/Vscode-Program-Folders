#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    long long trappingWater(int a[], int n)
    {
        int l = 0;
        int r = n - 1;

        int maxLeft = a[l];
        int maxRight = a[r];
        long long res = 0;

        while (l < r)
        {
            if (maxLeft < maxRight)
            {
                l++;
                maxLeft = max(maxLeft, a[l]);
                res += maxLeft - a[l];
            }
            else
            {
                r--;
                maxRight = max(maxRight, a[r]);
                res += maxRight - a[r];
            }
        }

        return res;
    }
};