#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int addRungs(vector<int> &rungs, int dist)
    {
        int prev_height = 0;
        int diff = 0;
        int count = 0;
        for (int i = 0; i < rungs.size(); i++)
        {
            diff = rungs[i] - prev_height;
            if (diff > dist)
            {
                count += diff / dist;

                // eg array is [1,2,6,8] and dist = 2 then if we do (6-2)i.e 4  4/2 we get 2 but we need only 1 rung in between 2 and 6 .: we check is 4%2 == 0 if true then reduce count by 1
                if (diff % dist == 0)
                    count--;
            }

            prev_height = rungs[i];
        }
        return count;
    }
};
