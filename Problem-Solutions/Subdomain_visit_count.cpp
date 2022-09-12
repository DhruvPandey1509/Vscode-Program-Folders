#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<string> subdomainVisits(vector<string> &cpdomains)
    {
        unordered_map<string, int> m;
        int num = 0;
        for (int i = 0; i < cpdomains.size(); i++)
        {
            for (int j = 0; j < cpdomains[i].size(); j++)
            {
                cout << cpdomains[i][j];
            }
            cout << endl;
        }

        for (int i = 0; i < cpdomains.size(); i++)
        {
            for (int j = 0; j < cpdomains[i].size(); j++)
            {
                if (cpdomains[i][j] == ' ')
                {
                    num = stoi(cpdomains[i].substr(0, j));
                    m[cpdomains[i].substr(j + 1, cpdomains[i].size())] += num;
                }
                if (cpdomains[i][j] == '.')
                {
                    m[cpdomains[i].substr(j + 1, cpdomains[i].size())] += num;
                }
            }
        }

        vector<string> res;
        for (auto i : m)
        {
            res.push_back(to_string(i.second) + " " + i.first);
        }

        return res;
    }
};