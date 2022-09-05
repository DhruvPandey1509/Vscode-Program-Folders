#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int lessThanK(int num, int rows, int cols)
    {
        int res = 0;
        for (int i = 1; i <= rows; i++)
        {
            res += min(num / i, cols);
        }
        return res;
    }
    int findKthNumber(int m, int n, int k)
    {
        int l = 1;
        int r = m * n;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (lessThanK(mid, m, n) < k)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return l;
    }
};
