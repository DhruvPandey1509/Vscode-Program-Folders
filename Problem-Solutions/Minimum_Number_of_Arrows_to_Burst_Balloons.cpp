#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end());
        int arrows = 1;

        int st = points[0][0];
        int en = points[0][1];

        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] <= en)
            {
                st = max(st, points[i][0]);
                en = min(en, points[i][1]);
            }
            else
            {
                arrows++;
                st = points[i][0];
                en = points[i][1];
            }
        }

        return arrows;
    }
};
