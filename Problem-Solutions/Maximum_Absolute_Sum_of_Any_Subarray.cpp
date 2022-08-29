#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        int max_positive_sum = 0, min_negative_sum = 0, curr_sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            curr_sum += nums[i];
            max_positive_sum = max(max_positive_sum, curr_sum);
            if (curr_sum < 0)
                curr_sum = 0;
        }
        curr_sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            curr_sum += nums[i];
            min_negative_sum = min(min_negative_sum, curr_sum);
            if (curr_sum > 0)
                curr_sum = 0;
        }

        return max(max_positive_sum, abs(min_negative_sum));
    }
};
