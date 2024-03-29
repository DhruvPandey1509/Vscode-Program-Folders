#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return false;

        int firstMin = INT_MAX;
        int secondMin = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= firstMin)
            {
                firstMin = nums[i];
            }
            else if (nums[i] <= secondMin)
            {
                secondMin = nums[i];
            }
            else
                return true;
        }

        return false;
    }
};