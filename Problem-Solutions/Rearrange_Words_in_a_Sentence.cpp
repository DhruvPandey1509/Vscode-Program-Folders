#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    string arrangeWords(string text)
    {
        map<int, vector<string>> m;
        int len = 0;
        string s = "";
        for (int i = 0; i < text.size(); i++)
        {
            if (text[i] == ' ')
            {
                m[len].push_back(s);
                s = "";
                len = 0;
            }
            else
            {
                s += tolower(text[i]);
                len++;
            }
        }
        m[len].push_back(s);
        string res = "";

        for (auto i : m)
        {
            for (auto str : i.second)
            {
                res += str + " ";
            }
        }
        res.pop_back();
        res[0] = toupper(res[0]);
        return res;
    }
};