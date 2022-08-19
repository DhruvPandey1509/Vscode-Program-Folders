#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        map<int, int> fm; // frequency map
        map<int, int> m;

        for (auto i : nums)
        {
            fm[i]++;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (fm[nums[i]] == 0)
                continue;

            if (m[nums[i] - 1] > 0)
            {
                fm[nums[i]]--;
                m[nums[i] - 1]--;
                m[nums[i]]++;
            }
            else if (fm[nums[i] + 1] > 0 and fm[nums[i] + 2] > 0)
            {
                fm[nums[i]]--;
                fm[nums[i] + 1]--;
                fm[nums[i] + 2]--;
                m[nums[i] + 2]++;
            }

            else
                return false;
        }

        return true;
    }
};