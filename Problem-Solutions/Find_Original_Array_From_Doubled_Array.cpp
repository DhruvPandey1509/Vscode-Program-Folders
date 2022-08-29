#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        unordered_map<int, int> freq;
        for (auto i : changed)
        {
            freq[i]++;
        }
        sort(changed.begin(), changed.end());

        vector<int> res;
        for (auto i : changed)
        {
            if (freq[i] and freq[i * 2])
            {
                freq[i]--;
                freq[i * 2]--;
                res.push_back(i);
            }
        }
        for (auto i : freq)
        {
            if (i.second)
                return {};
        }

        return res;
    }
};
