#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool digitCount(string num)
    {
        map<char, int> m;
        for (int i = 0; i < num.size(); i++)
        {
            m[num[i]]++;
        }
        for (int i = 0; i < num.size(); i++)
        {
            if (m['0' + i] != num[i] - '0')
                return false;
        }
        return true;
    }
};
// int to char :- '0' + i
// char to int :- i - '0'