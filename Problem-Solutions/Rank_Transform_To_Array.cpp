#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }
    vector<int> arrayRankTransform(vector<int> &a)
    {
        if (a.size() == 0)
            return {};

        vector<pair<int, int>> v;

        for (int i = 0; i < a.size(); i++)
        {
            v.push_back({a[i], i});
        }

        sort(v.begin(), v.end());

        int rank = 1;
        int x = v[0].first;
        v[0].first = rank;

        for (int i = 1; i < v.size(); i++)
        {
            if (v[i].first == x)
            {
                v[i].first = rank;
            }
            else
            {
                rank++;
                x = v[i].first;
                v[i].first = rank;
            }
        }

        sort(v.begin(), v.end(), cmp);
        vector<int> res;
        for (int i = 0; i < v.size(); i++)
        {
            res.push_back(v[i].first);
        }

        return res;
    }
};