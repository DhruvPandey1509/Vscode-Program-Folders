#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string largestGoodInteger(string num)
    {

        string res = "";
        int maxNum = INT_MIN;

        int count = 1;
        int x = num[0];

        for (int i = 1; i < num.size(); i++)
        {
            if (num[i] == x)
                count++;
            else
            {
                x = num[i];
                count = 1;
            }
            if (count >= 3)
            {
                maxNum = max(maxNum, x - '0');
            }
        }

        if (maxNum != INT_MIN)
        {
            int i = 3;
            while (i--)
            {
                res += '0' + maxNum;
            }
        }

        return res;
    }
};