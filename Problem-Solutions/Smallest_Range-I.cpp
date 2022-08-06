#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int smallestRangeI(vector<int> &nums, int k)
    {
        int maxEle = *max_element(nums.begin(), nums.end());
        int minEle = *min_element(nums.begin(), nums.end());

        int res = maxEle - minEle - 2 * k;

        if (res < 0)
            return 0;

        return res;
    }
};