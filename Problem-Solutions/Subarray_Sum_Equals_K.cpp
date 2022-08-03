#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        int curr_sum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            curr_sum += nums[i];
            if (curr_sum == k)
                count++;

            if (m.find(curr_sum - k) != m.end())
            {
                count += m[curr_sum - k];
            }
            m[curr_sum]++;
        }

        return count;
    }
};