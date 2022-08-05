#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int maxSumDivThree(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int sum = 0;
        vector<int> v1; // storing elements giving remainder 1;
        vector<int> v2; // storing elements giving remainder 2;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (nums[i] % 3 == 1)
            {
                v1.push_back(nums[i]);
            }
            else if (nums[i] % 3 == 2)
            {
                v2.push_back(nums[i]);
            }
        }

        if (sum % 3 == 0)
            return sum;

        int sub1 = INT_MAX;
        int sub2 = INT_MAX;
        int sub = INT_MAX;

        if (sum % 3 == 1) // remainder 1
        {
            if (v1.size() > 0)
            {
                sub1 = v1[0];
            }

            if (v2.size() > 1)
            {
                sub2 = v2[0] + v2[1];
            }
        }
        else if (sum % 3 == 2) // remainder 2
        {
            if (v1.size() > 1)
            {
                sub1 = v1[0] + v1[1];
            }

            if (v2.size() > 0)
            {
                sub2 = v2[0];
            }
        }

        sub = min(sub1, sub2);

        if (sub != INT_MAX)
        {
            return sum - sub;
        }

        return 0;
    }
};