#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {

        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
        {
            if (nums[0] < nums[1])
                return nums[0];
            else
                return nums[1];
        }
        int lo = 0, hi = nums.size() - 1;

        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == nums[hi] and nums[mid] == nums[lo])
            {
                lo++;
                hi--;
            }
            else if (nums[mid] <= nums[hi])
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return nums[lo];
    }
};