#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &weights, int days, int mid)
    {
        int count = 1, sum = 0;

        for (auto w : weights)
        {
            if (sum + w <= mid)
                sum += w;
            else
            {
                count++;
                if (count > days)
                    return false;
                sum = w;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {

        long sum = 0;
        int maxVal = 0;

        for (auto i : weights)
        {
            sum += i;
            maxVal = max(maxVal, i);
        }

        int res = -1;
        int lo = maxVal, hi = sum;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (isPossible(weights, days, mid))
            {
                res = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return res;
    }
};