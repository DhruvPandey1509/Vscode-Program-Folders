#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {

        int sum = 0;
        bool isUnique = true;
        int n = nums.size();
        vector<int> v(10005, 0);

        int res = INT_MIN;
        int st = -1;
        int en = 0;

        while (st < n && en < n)
        {
            if (v[nums[en]] == 0)
            {
                sum += nums[en];
                v[nums[en]] = 1;
                en++;
            }
            else
            {
                st++;
                sum -= nums[st];
                v[nums[st]] = 0;
            }

            res = max(sum, res);
        }
        return res;
    }
};