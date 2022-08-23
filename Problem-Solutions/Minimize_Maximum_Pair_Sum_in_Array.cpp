#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int i = 0;
        int j = nums.size() - 1;
        int res = INT_MIN;
        while (i < j)
        {
            int sum = nums[i] + nums[j];
            res = max(sum, res);
            i++;
            j--;
        }

        return res;
    }
};
