#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int partitionArray(vector<int> &nums, int k)
    {

        sort(nums.begin(), nums.end());
        int start = 0, count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (abs(nums[i] - nums[start]) > k)
            {
                count++;
                start = i;
            }
        }

        return count + 1;
    }
};