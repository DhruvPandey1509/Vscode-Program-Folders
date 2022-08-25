#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        string res = "";
        int increment = 2 * (numRows - 1);

        for (int r = 0; r < numRows; r++)
        {
            for (int i = r; i < s.size(); i += increment)
            {
                res += s[i];
                int icr = increment - 2 * r;
                if (r > 0 and r < numRows - 1 and (i + icr) < s.size())
                {
                    res += s[i + icr];
                }
            }
        }

        return res;
    }
};