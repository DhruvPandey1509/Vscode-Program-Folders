#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    static bool cmp(const pair<int, int> &p1, const pair<int, int> &p2)
    {
        return p1.first > p2.first;
    }
    int largestValsFromLabels(vector<int> &values, vector<int> &labels, int numWanted, int useLimit)
    {
        vector<pair<int, int>> v;
        unordered_map<int, int> limit;

        for (int i = 0; i < values.size(); i++)
        {
            v.push_back({values[i], labels[i]});
            limit[labels[i]] = useLimit;
        }
        sort(v.begin(), v.end(), cmp);
        int res = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (limit[v[i].second])
            {
                res += v[i].first;
                limit[v[i].second] -= 1;
                numWanted -= 1;
            }
            if (!numWanted)
                break;
        }
        return res;
    }
};
