#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        vector<int> count(n, 0);

        for (int i = 0; i < roads.size(); i++)
        {
            count[roads[i][0]]++;
            count[roads[i][1]]++;
        }

        sort(count.begin(), count.end());
        long long res = 0;
        for (long long i = 0; i < n; i++)
        {
            res += (i + 1) * count[i];
        }

        return res;
    }
};