#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0 || nums.size() == 1)
            return nums.size();

        map<int, int> m;
        int prev = INT_MAX;
        for (auto i : nums)
        {
            m[i]++;
            prev = min(prev, i);
        }
        int maxLen = 0;
        int currLen = 1;
        for (auto i : m)
        {
            if (i.first == prev)
            {
                continue;
            }
            else if (i.first == prev + 1)
            {
                currLen++;
            }
            else
            {
                currLen = 1;
            }
            maxLen = max(maxLen, currLen);
            prev = i.first;
        }
        maxLen = max(maxLen, currLen);
        return maxLen;
    }
};
