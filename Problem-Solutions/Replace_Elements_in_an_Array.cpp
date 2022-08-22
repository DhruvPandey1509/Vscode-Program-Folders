#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> arrayChange(vector<int> &nums, vector<vector<int>> &operations)
    {
        unordered_map<int, int> m; // first = nums[idx]  second = idx

        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]] = i;
        }

        for (int i = 0; i < operations.size(); i++)
        {
            int x = operations[i][0];            // key to be changed
            int replace_with = operations[i][1]; // new key to replace old key

            // changing the key in the map
            auto changeKey = m.find(x);
            auto val = changeKey->second;
            m.erase(changeKey);
            m.insert({replace_with, val});
        }

        vector<int> v(nums.size(), 0);
        for (auto i : m)
        {
            v[i.second] = i.first;
        }

        return v;
    }
};