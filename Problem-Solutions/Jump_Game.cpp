#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {

        if (nums.size() == 1)
        {
            return true;
        }

        int reach = 0;

        int n = nums.size() - 1;

        for (int i = 0; i <= n; i++)
        {

            reach = max(reach, i + nums[i]);
            if (reach == i)
            {
                return false;
            }

            else
            {
                if (reach >= n)
                {
                    return true;
                }
            }
        }

        return true;
    }
};