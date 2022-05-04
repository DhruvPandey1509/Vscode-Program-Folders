#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    // Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b)
    {
        if (a.size() != b.size())
        {
            return false;
        }
        vector<char> v(26, 0);

        for (int i = 0; i < a.size(); i++)
        {
            v[a[i] - 'a']++;
        }

        for (int i = 0; i < b.size(); i++)
        {
            v[b[i] - 'a']--;
        }

        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] != 0)
            {
                return false;
            }
        }

        return true;
    }
};