#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> res;

        map<int, int> m; // key = nums, value = frequncy

        for (auto i : nums)
        {
            m[i]++;
        }

        for (auto i : m)
        {
            if (i.second == 2)
                res.push_back(i.first);
        }

        return res;
    }
};