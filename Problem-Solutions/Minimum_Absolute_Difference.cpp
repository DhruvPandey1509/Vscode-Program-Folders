#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int minDiff = arr[1] - arr[0];

        vector<vector<int>> res = {};

        res.push_back({arr[0], arr[1]});

        for (int i = 2; i < arr.size(); i++)
        {
            if (arr[i] - arr[i - 1] == minDiff)
            {
                res.push_back({arr[i - 1], arr[i]});
            }
            else if (arr[i] - arr[i - 1] < minDiff)
            {
                res.clear();
                minDiff = arr[i] - arr[i - 1];
                res.push_back({arr[i - 1], arr[i]});
            }
        }

        return res;
    }
};