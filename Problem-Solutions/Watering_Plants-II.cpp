#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minimumRefill(vector<int> &plants, int capacityA, int capacityB)
    {
        int count = 0;
        int n = plants.size();
        int a = capacityA;
        int b = capacityB;

        int st = 0;
        int en = n - 1;

        while (st <= en)
        {
            if (st == en)
            {
                if (a > b)
                {
                    if (a < plants[st])
                    {
                        count++;
                    }
                }
                else
                {
                    if (b < plants[en])
                    {
                        count++;
                    }
                }
                break;
            }
            if (a < plants[st])
            {
                a = capacityA;
                count++;
            }
            if (b < plants[en])
            {
                b = capacityB;
                count++;
            }
            a -= plants[st];
            b -= plants[en];
            st++;
            en--;
        }

        return count;
    }
};