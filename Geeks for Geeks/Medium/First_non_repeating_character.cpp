#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string FirstNonRepeating(string a)
    {
        map<char, int> m;
        int j = 0;
        string res = "";

        for (int i = 0; i < a.size(); i++)
        {
            m[a[i]]++;
            while (m[a[j]] != 1 && j <= i)
            {
                j++;
            }

            res += j > i ? '#' : a[j];
        }

        return res;
    }
};