#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    bool closeStrings(string w1, string w2)
    {

        if (w1.size() != w2.size())
            return false;

        unordered_map<int, int> w1_f, w2_f, rep;
        for (char c : w1)
        {
            w1_f[c]++;
        }
        for (char c : w2)
        {
            w2_f[c]++;
        }
        for (auto i : w1_f)
        {
            rep[i.second]++;
        }
        for (auto i : w2_f)
        {
            if (!w1_f[i.first] || !rep[i.second]--)
                return false;
        }

        return true;
    }
};
