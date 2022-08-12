#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            int sum = 0;
            for (auto i : nums)
            {
                sum += ceil((float)i / m);
            }

            if (sum > threshold)
                l = m + 1;
            else
                r = m - 1;
        }

        return l;
    }
};