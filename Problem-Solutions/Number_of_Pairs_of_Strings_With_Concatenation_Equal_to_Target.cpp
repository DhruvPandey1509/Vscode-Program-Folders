#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int numOfPairs(vector<string> &nums, string target)
    {
        unordered_map<string, int> m;
        int count = 0;
        for (auto i : nums)
        {
            m[i]++;
        }

        for (string prefix : nums)
        {
            if (target.substr(0, prefix.size()) != prefix)
                continue;

            string suffix = target.substr(prefix.size());
            if (m.find(suffix) != m.end())
            {
                int c = m[suffix];
                count += prefix == suffix ? c - 1 : c;
            }
        }

        return count;
    }
};
/**

Brute Force: N(n^2)

Using Hash Set: O(n)
====================
1. First count all items and put in map.
2. Traverse the array. Find remaining suffix in map.
3. If map gives us count C add C into result.
4. Exception: If prefix and suffix are same then add C-1 into result.

**/
