#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int res = 0;
        int val = 0;
        for (char c : columnTitle)
        {
            val = c - 'A' + 1; // 1 is added because we starting counting A from 1 not 0
            res = res * 26 + val;
            val = 0;
        }

        return res;
    }
};