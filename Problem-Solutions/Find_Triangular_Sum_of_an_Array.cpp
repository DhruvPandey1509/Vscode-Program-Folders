#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int triangularSum(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];

        if (nums.size() == 2)
            return (nums[0] + nums[1]) % 10;

        vector<int> v;
        for (int i = 1; i < nums.size(); i++)
        {
            v.push_back((nums[i - 1] + nums[i]) % 10);
        }

        nums = v;
        v.clear();

        while (nums.size() != 1)
        {
            for (int i = 1; i < nums.size(); i++)
            {
                v.push_back((nums[i - 1] + nums[i]) % 10);
            }
            nums = v;
            v.clear();
        }

        return nums[0];
    }
}; 