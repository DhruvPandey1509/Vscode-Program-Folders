#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int st = 0;
        int en = nums.size() - 1;

        while (st < en)
        {
            if (nums[st] % 2 != 0)
            {
                while (nums[en] % 2 != 0 and en > st)
                {
                    en--;
                }
                if (nums[en] % 2 != 0)
                    break;
                swap(nums[st], nums[en]);
            }
            st++;
        }

        return nums;
    }
};