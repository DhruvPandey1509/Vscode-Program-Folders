#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int romanToDecimal(string &s)
    {
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int sum = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (i + 1 < s.size() && m[s[i + 1]] > m[s[i]])
            {
                sum += m[s[i + 1]] - m[s[i]];
                i++;
            }
            else
            {
                sum += m[s[i]];
            }
        }
        return sum;
    }
};