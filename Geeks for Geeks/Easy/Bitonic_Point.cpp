#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int findMaximum(int a[], int n)
    {
        int lo = 0;
        int hi = n - 1;

        while (hi >= lo)
        {
            int mid = lo + (hi - lo) / 2;

            if (a[mid] > a[mid + 1] && a[mid] > a[mid - 1])
                return a[mid];

            else if (a[mid] > a[mid + 1] && a[mid] < a[mid - 1])
            {
                hi = mid - 1;
            }
            else if (a[mid] < a[mid + 1] && a[mid] > a[mid - 1])
            {
                lo = mid + 1;
            }
        }
        return a[n - 1];
    }
};