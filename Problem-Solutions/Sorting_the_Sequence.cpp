#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    static bool cmp(pair<string, int> a, pair<string, int> b)
    {
        return a.second < b.second;
    }
    string sortSentence(string s)
    {
        vector<pair<string, int>> v;

        string str = "";

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                int num = s[i - 1] - '0';
                v.push_back({str.substr(0, str.size() - 1), num});
                str = "";
            }
            else
            {
                str += s[i];
            }
        }

        int num = str[str.size() - 1] - '0';
        v.push_back({str.substr(0, str.size() - 1), num});

        sort(v.begin(), v.end(), cmp);

        string res = "";

        for (int i = 0; i < v.size() - 1; i++)
        {
            res += v[i].first + " ";
        }

        int n = v.size() - 1;
        res += v[n].first;
        return res;
    }
};