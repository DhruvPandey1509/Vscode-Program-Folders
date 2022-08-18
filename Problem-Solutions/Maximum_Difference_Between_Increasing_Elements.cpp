#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int mini = nums[0], res = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > mini)
            {
                res = max(res, nums[i] - mini);
            }

            else
                mini = nums[i];
        }
        return res;
    }
};