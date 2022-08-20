#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int countKDifference(vector<int> &nums, int k)
    {

        unordered_map<int, int> m;
        int count = 0;
        for (auto i : nums)
        {
            count += m[i + k] + m[i - k];
            m[i]++;
        }

        return count;
    }
};