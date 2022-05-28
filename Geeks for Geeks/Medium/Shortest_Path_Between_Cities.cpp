#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int shortestPath(int x, int y)
    {
        if (x == y)
            return 0;
        int count = 0;
        while (x != y)
        {
            if (x > y and x != 1)
            {
                x /= 2;
                count++;
                if (x == y)
                    return count;
            }
            if (y > x and y != 1)
            {
                y /= 2;
                count++;
                if (y == x)
                    return count;
            }
        }
        return count;
    }
};