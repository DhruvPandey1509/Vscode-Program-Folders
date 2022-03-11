#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        int size = nums.size();
        int lo = 0;
        int hi = size - 1;

        vector<int> res(2, -1);

        while (lo < hi)
        {
            if (nums[lo] + nums[hi] == target)
            {
                res[0] = lo + 1;
                res[1] = hi + 1;
                break;
            }
            else if (nums[lo] + nums[hi] > target)
            {
                hi--;
            }
            else
            {
                lo++;
            }
        }
        return res;
    }
};