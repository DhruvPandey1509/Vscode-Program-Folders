#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            if (nums[0] == 0)
                return 0;

            return 1;
        }
        int steps = 0;
        sort(nums.begin(), nums.end());

        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] == 0)
            {
                i++;
                continue;
            }
            else
            {
                int j = i + 1;
                while (j < nums.size())
                {
                    nums[j] = nums[j] - nums[i];
                    j++;
                }
                nums[i] = 0;
                steps++;
            }
        }

        return steps;
    }
};