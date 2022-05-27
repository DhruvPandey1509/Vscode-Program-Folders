#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minMoves(int t, int md)
    {

        if (md == 0)
        {
            return t - 1;
        }
        int count = 0;
        while (t > 1)
        {
            if (t % 2 == 0 and md > 0)
            {
                t /= 2;
                md--;
                count++;
                if (t == 1)
                    return count;
                if (md == 0)
                    return count + t - 1;
            }
            else
            {
                t--;
                count++;
            }
        }
        return count;
    }
};