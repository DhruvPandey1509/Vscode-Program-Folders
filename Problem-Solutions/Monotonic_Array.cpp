#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {

        int dir = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int d = (nums[i] == nums[i + 1]) ? 0 : (nums[i] > nums[i + 1]) ? -1
                                                                           : 1;
            if (d && dir == 0)
                dir = d;
            if (d && dir && d != dir)
                return false;
        }

        return true;
    }
};