#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int maximumTastiness(vector<int> &price, int k)
    {
        int n = price.size();
        sort(price.begin(), price.end());

        int l = 0, r = 1e9, res = l;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int first = price[0];
            int candies = 1;
            for (int i = 1; i < n; i++)
            {
                if (price[i] - first >= mid)
                {
                    candies++;
                    first = price[i];
                }
            }
            if (candies >= k)
            {
                res = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return res;
    }
};
