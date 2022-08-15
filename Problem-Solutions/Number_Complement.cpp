#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int findComplement(int num)
    {
        int x;

        for (int i = 0; i < num; i++)
        {
            if (pow(2, i) == num)
            {
                x = pow(2, i + 1) - 1;
                break;
            }
            else if (pow(2, i) > num)
            {
                x = pow(2, i) - 1;
                break;
            }
        }

        return x ^ num;
    }
};