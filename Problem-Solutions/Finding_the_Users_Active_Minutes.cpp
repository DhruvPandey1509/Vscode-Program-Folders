#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k)
    {
        map<int, set<int>> m;
        vector<int> v(k, 0);
        for (auto log : logs)
        {
            m[log[0]].insert(log[1]);
        }

        for (auto i : m)
        {
            v[i.second.size() - 1]++;
        }

        return v;
    }
};