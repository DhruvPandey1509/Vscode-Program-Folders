#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(string a[], int n)
    {
        string res = a[0];

        for (int i = 1; i < n; i++)
        {
            string s = a[i];
            for (int j = 0; j < res.length(); j++)
            {
                if (s[j] != res[j])
                {
                    res = res.substr(0, j);
                    break;
                }
            }
        }

        if (res.size() <= 0)
            return "-1";

        return res;
    }
};