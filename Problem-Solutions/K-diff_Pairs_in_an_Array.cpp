#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        for (auto i : nums)
        {
            m[i]++;
        }

        int count = 0;

        if (k > 0)
        {
            for (auto i : m)
            {
                if (m.find(i.first + k) != m.end())
                    count++;
            }
        }
        else
        {
            for (auto i : m)
            {
                if (i.second > 1)
                    count++;
            }
        }
        return count;
    }
};
