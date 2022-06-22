#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        priority_queue<int> p;
        int i;
        int n = heights.size();
        for (i = 0; i < n - 1; i++)
        {
            int temp = heights[i + 1] - heights[i];
            if (temp > 0)
            {
                bricks -= temp;
                p.push(temp);
                while (bricks < 0 && ladders > 0 && !p.empty())
                {
                    bricks += p.top();
                    ladders--;
                    p.pop();
                }
            }

            if (bricks < 0)
                return i;
        }
        return i;
    }
};