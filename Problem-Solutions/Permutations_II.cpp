#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    unordered_map<int, int> m;
    vector<int> v;
    void permutations(vector<int> nums, int idx)
    {
        if (idx == nums.size())
        {
            res.push_back(v);
            return;
        }

        for (auto i : m)
        {
            int key = i.first;  // element
            int val = i.second; // its frequency

            if (val == 0) // element used completely and cannot be used further
                continue;

            v.push_back(key);
            m[key]--;

            permutations(nums, idx + 1);

            v.pop_back();
            m[key]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        // storing frequency of elements
        for (auto i : nums)
        {
            m[i]++;
        }
        permutations(nums, 0);
        return res;
    }
};