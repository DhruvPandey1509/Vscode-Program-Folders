#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int bSearch(vector<int> nums, int target)
    {
        int low = 0, high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
    }
    vector<int> searchRange(vector<int> &v, int target)
    {
        if (v.size() == 0)
        {
            return {-1, -1};
        }
        int p2 = bSearch(v, target);     // it will get one index greater then the last index of target
        int p1 = bSearch(v, target - 1); // t will get the index of the first index of the start target

        if (p1 == p2) // that means element is not present.
        {
            return {-1, -1};
        }

        return {p1, p2 - 1};
    }
};