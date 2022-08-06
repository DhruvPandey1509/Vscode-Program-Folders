#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool static cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {

        vector<pair<int, int>> v; // key =

        for (int i = 0; i < profit.size(); i++)
        {
            v.push_back({difficulty[i], profit[i]});
        }

        // sorting in descending order of profit
        sort(v.begin(), v.end(), cmp);

        // sorting worker in descending order
        sort(worker.rbegin(), worker.rend());

        int res = 0;
        int i = 0, j = 0;

        while (i < worker.size() and j < v.size())
        {
            if (worker[i] >= v[j].first)
            {
                res += v[j].second;
                i++;
            }
            else
            {
                j++;
            }
        }

        return res;
    }
};