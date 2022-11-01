#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    string licenseKeyFormatting(string s, int k)
    {
        int n = s.size();
        string res = "", str = "";

        int count = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (count == k)
            {
                count = 0;
                res += str + "-";
                str = "";
            }
            if (s[i] != '-')
            {
                count++;
                str += toupper(s[i]);
            }
        }
        if (str != "")
        {
            res += str;
        }
        if (res.size() == 0)
            return res;

        reverse(res.begin(), res.end());
        if (res[0] == '-')
        {
            res = res.substr(1);
        }

        return res;
    }
};
