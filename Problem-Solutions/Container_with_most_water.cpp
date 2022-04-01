#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {

        int st = 0;
        int en = height.size() - 1;
        int water = 0;
        while (st < en)
        {
            water = max(water, min(height[st], height[en]) * (en - st));
            if (height[st] < height[en])
            {
                st++;
            }
            else
            {
                en--;
            }
        }
        return water;
    }
};