#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    static bool cmp(pair<string, int> a, pair<string, int> b)
    {
        if (a.second == b.second)
        {
            return a.first < b.first;
        }
        return a.second > b.second;
    }
    vector<string> topKFrequent(vector<string> &words, int k)
    {

        // storing the frequency of each word in map;
        map<string, int> m;
        for (auto i : words)
        {
            m[i]++;
        }

        // storing the word and its frequency in vector-pair
        vector<pair<string, int>> v;
        for (auto i : m)
        {
            v.push_back({i.first, i.second});
        }
        sort(v.begin(), v.end(), cmp); // sorting on the basis of frequency

        vector<string> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(v[i].first);
        }

        return res;
    }
};
