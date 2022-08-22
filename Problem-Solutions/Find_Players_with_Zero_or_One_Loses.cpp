#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        unordered_map<int, int> won;
        unordered_map<int, int> lost;

        for (int i = 0; i < matches.size(); i++)
        {
            won[matches[i][0]]++;
            lost[matches[i][1]]++;
        }
        vector<int> l;
        for (auto i : lost)
        {
            if (won.find(i.first) != won.end())
            {
                auto it = won.find(i.first);
                won.erase(it);
            }
            if (i.second == 1)
            {
                l.push_back(i.first);
            }
        }
        vector<int> w;
        for (auto i : won)
        {
            w.push_back(i.first);
        }

        sort(w.begin(), w.end());
        sort(l.begin(), l.end());

        return {w, l};
    }
};