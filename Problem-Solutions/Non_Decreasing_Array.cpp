#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        bool flag = false;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1] and !flag)
            {
                if (i == 0 || nums[i + 1] >= nums[i - 1])
                    nums[i] = nums[i + 1];
                else
                    nums[i + 1] = nums[i];

                flag = true;
            }
            else if (nums[i] > nums[i + 1])
                return false;
        }

        return true;
    }
};