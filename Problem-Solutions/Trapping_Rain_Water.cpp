#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {

        int l = 0, r = height.size() - 1;

        int leftMax = height[l];
        int rightMax = height[r];
        int res = 0;
        while (l < r)
        {
            if (leftMax < rightMax)
            {
                l++;
                leftMax = max(height[l], leftMax);
                res += leftMax - height[l];
            }
            else
            {
                r--;
                rightMax = max(height[r], rightMax);
                res += rightMax - height[r];
            }
        }

        return res;
    }
};