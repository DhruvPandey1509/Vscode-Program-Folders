#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int canBeTypedWords(string text, string brokenLetters)
    {
        map<char, int> m;

        for (int i = 0; i < brokenLetters.size(); i++)
        {
            m[brokenLetters[i]] = 1;
        }

        int res = 0;

        vector<string> v;
        string s = "";
        for (int i = 0; i < text.size(); i++)
        {
            if (text[i] == ' ')
            {
                v.push_back(s);
                s = "";
            }
            else
            {
                s += text[i];
            }
        }
        v.push_back(s);
        bool flag = false; // true = broken;
        for (int i = 0; i < v.size(); i++)
        {
            flag = false;
            string s = v[i];
            for (int i = 0; i < s.size(); i++)
            {
                if (m.find(s[i]) != m.end())
                {
                    flag = true;
                    break;
                }
            }

            if (!flag)
                res++;
        }

        return res;
    }
};