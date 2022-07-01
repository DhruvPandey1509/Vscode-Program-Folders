#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {

        vector<pair<int, int>> v;

        for (int i = 0; i < boxTypes.size(); i++)
        {
            v.push_back({boxTypes[i][1], boxTypes[i][0]});
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        int res = 0;
        for (int i = 0; i < v.size(); i++)
        {
            int size = v[i].second;
            int cost = v[i].first;
            if (truckSize >= size)
            {
                res += size * cost;
                truckSize = truckSize - size;
            }

            else if (truckSize > 0)
            {
                res += cost * truckSize;
                break;
            }
        }

        return res;
    }
};