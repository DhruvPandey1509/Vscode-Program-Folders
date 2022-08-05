#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> m; // key = arr element and value = frequency

        for (auto i : arr)
        {
            m[i]++;
        }

        unordered_map<int, int> mp;
        for (auto i : m)
        {
            if (mp.find(i.second) != mp.end())
                return false;
            else
            {
                mp[i.second] = 1;
            }
        }

        return true;
    }
};