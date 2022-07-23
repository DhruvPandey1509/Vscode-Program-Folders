#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int maxLevel(int h, int m)
    {
        int flag = 0;
        int count = 0;

        while (h > 0 and m > 0)
        {
            int temp = flag;
            if (flag != 1)
            {
                h += 3;
                m += 2;
                flag = 1;
            }
            else if ((h - 5 > 0 and m - 10 > 0) and (flag != 2))
            {
                h -= 5;
                m -= 10;
                flag = 2;
            }
            else if ((h - 20 > 0) and (flag != 3))
            {
                h -= 20;
                m += 5;
                flag = 3;
            }

            if (temp == flag)
            {
                break;
            }

            count++;
        }

        return count;
    }
};