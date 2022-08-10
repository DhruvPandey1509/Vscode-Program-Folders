#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        unordered_map<char, int> m;
        for (char c : chars)
        {
            m[c]++;
        }

        int res = 0;
        bool flag = false;

        for (auto word : words)
        {
            unordered_map<char, int> w;
            for (char c : word)
            {
                w[c]++;
            }
            flag = true;
            for (auto i : w)
            {
                if (m.find(i.first) == m.end() || m[i.first] < i.second)
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                res += word.size();
            }
        }
        return res;
    }
};