#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> m; // key = (prefix sum upto current element) mod k  value = index

        m.insert({0, -1});
        int sum = 0;
        int rem = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            rem = sum % k;
            if (m.find(rem) == m.end())
            {
                m[rem] = i;
            }
            else if (i - m[rem] > 1)
            {
                return true;
            }
        }

        return false;
    }
};