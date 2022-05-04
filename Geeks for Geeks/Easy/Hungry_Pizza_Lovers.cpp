#include "bits/stdc++.h"
using namespace std;

vector<int> permute(vector<vector<int>> &a, int n)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({a[i][0] + a[i][1], i + 1});
    }

    sort(v.begin(), v.end());
    vector<int> res(v.size());

    for (int i = 0; i < n; i++)
    {
        res[i] = v[i].second;
    }
    return res;
}