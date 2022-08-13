#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words)
    {
        vector<int> m(26, 0);
        string res = "";
        for (auto i : licensePlate)
        {
            if (isalpha(i))
            {
                m[tolower(i) - 'a']++;
            }
        }

        for (auto word : words)
        {
            vector<int> v = m;
            for (auto s : word)
            {
                v[tolower(s) - 'a']--;
            }

            bool flag = true;
            for (auto i : v)
            {
                if (i > 0)
                {
                    flag = false;
                    break;
                }
            }

            if (flag and (res == "" || res.size() > word.size()))
            {
                res = word;
            }
        }

        return res;
    }
};