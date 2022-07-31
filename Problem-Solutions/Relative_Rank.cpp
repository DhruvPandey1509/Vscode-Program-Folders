#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        int n = score.size();
        if (n == 1)
            return {"Gold Medal"};

        if (n == 2)
        {
            vector<string> res(2);
            if (score[0] > score[1])
            {
                res[0] = "Gold Medal";
                res[1] = "Silver Medal";
            }
            else
            {
                res[1] = "Gold Medal";
                res[0] = "Silver Medal";
            }

            return res;
        }

        vector<pair<int, int>> v; // first = score[index], second = index
        for (int i = 0; i < n; i++)
        {
            v.push_back({score[i], i});
        }

        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        vector<string> res(n);

        res[v[0].second] = "Gold Medal";
        res[v[1].second] = "Silver Medal";
        res[v[2].second] = "Bronze Medal";

        for (int i = 3; i < n; i++)
        {
            res[v[i].second] = to_string(i + 1);
        }

        return res;
    }
};