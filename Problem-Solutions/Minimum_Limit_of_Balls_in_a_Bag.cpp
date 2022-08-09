#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int r = *max_element(nums.begin(), nums.end());
        int l = 1;
        int res = r;
        while (l < r)
        {
            int penalty = l + (r - l) / 2;

            int ops = 0;

            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] > penalty)
                {
                    if (nums[i] % penalty == 0)
                    {
                        ops += nums[i] / penalty - 1;
                    }
                    else
                    {
                        ops += nums[i] / penalty;
                    }
                }
            }

            if (ops <= maxOperations)
            {
                res = penalty;
                r = penalty;
            }
            else
            {
                l = penalty + 1;
            }
        }

        return res;
    }
};