#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int destroyTargets(vector<int> &nums, int space)
    {
        map<int, int> m;
        int high = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i] % space]++;
            high = max(high, m[nums[i] % space]);
        }
        int res = INT_MAX;

        for (int i = 0; i < nums.size(); i++)
        {
            if (m[nums[i] % space] == high)
                res = min(res, nums[i]);
        }
        return res;
    }
};
