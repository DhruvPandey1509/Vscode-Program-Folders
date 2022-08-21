#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int monotoneIncreasingDigits(int n)
    {

        string num = to_string(n);
        int pos = -1;
        for (int i = 1; i < num.size(); i++)
        {
            if (num[i] < num[i - 1])
            {
                pos = i - 1;
                break;
            }
        }

        if (pos == -1)
            return n;

        pos = num.find(num[pos]);
        num[pos] = (num[pos] - '0' - 1) + '0';

        for (int i = pos + 1; i < num.size(); i++)
        {
            num[i] = '9';
        }

        return stoi(num);
    }
};