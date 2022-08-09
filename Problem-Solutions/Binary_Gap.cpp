#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int binaryGap(int n)
    {
        // coverting to binary equivalent
        string res = "";
        while (n > 0)
        {
            res = to_string(n % 2) + res;
            n = n / 2;
        }

        vector<int> v;
        for (int i = 0; i < res.size(); i++)
        {
            if (res[i] == '1')
            {
                v.push_back(i);
            }
        }

        int maxDis = 0;
        for (int i = 0; i < v.size() - 1; i++)
        {
            maxDis = max(abs(v[i + 1] - v[i]), maxDis);
        }

        return maxDis;
    }
};