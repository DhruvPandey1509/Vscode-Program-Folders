#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> v;
        int count = 1;

        v.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == v.back())
            {
                if (count == 1)
                {
                    v.push_back(nums[i]);
                    count = 2;
                }
            }
            else
            {
                v.push_back(nums[i]);
                count = 1;
            }
        }

        for (int i = 0; i < v.size(); i++)
        {
            nums[i] = v[i];
        }

        return v.size();
    }
};