#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {

        int res = 0;
        int sum = 0;
        int len = 0;
        int idx = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            len++;
            while (sum >= target)
            {
                if (res == 0)
                {
                    res = len;
                }
                res = min(res, len);
                sum -= nums[idx];
                len--;
                idx++;
            }
        }
        return res;
    }
};