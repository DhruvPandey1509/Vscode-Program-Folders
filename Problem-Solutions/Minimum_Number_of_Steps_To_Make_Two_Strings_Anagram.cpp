#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minSteps(string s, string t)
    {
        vector<int> v(26, 0);
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            v[s[i] - 'a']++;
            v[t[i] - 'a']--;
        }

        for (int i = 0; i < v.size(); i++)
        {
            count += abs(v[i]);
        }
        // only half of unequal are to be replaced in order to make strings anagram
        return count >> 1;
    }
};