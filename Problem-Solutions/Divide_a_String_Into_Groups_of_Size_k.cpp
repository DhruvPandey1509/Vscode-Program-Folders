#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<string> divideString(string s, int k, char fill)
    {
        int count = 0;
        int i = 0;

        string str = "";
        vector<string> res;

        while (i < s.size())
        {
            str += s[i];
            count++;

            if (count == k)
            {
                count = 0;
                res.push_back(str);
                str = "";
            }

            i++;
        }

        if (str != "")
        {
            while (count < k)
            {
                str += fill;
                count++;
            }

            res.push_back(str);
        }

        return res;
    }
};