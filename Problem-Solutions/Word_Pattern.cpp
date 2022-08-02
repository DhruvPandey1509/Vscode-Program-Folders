#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        vector<string> v;
        string res = "";

        // adding words in string of vector
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                v.push_back(res);
                res = "";
            }
            else
            {
                res += s[i];
            }
        }
        v.push_back(res); // last word of string s

        if (v.size() != pattern.size())
            return false;

        unordered_map<char, string> m;
        set<string> st; // to check if some word of string s or v is assigned to different chars in pattern.

        for (int i = 0; i < pattern.size(); i++)
        {
            if (m.find(pattern[i]) != m.end())
            {
                if (m[pattern[i]] != v[i])
                    return false;
            }
            else
            {
                if (st.count(v[i]) > 0)
                {
                    return false; // same word for another char
                }
                m[pattern[i]] = v[i];
                st.insert(v[i]);
            }
        }

        return true;
    }
};