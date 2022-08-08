#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        map<char, int> m;
        int n = words.size();
        for (auto s : words)
        {
            for (char ch : s)
            {
                m[ch]++;
            }
        }

        for (auto i : m)
        {
            if (i.second % n != 0)
                return false;
        }

        return true;
    }
};