#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string digitSum(string s, int k)
    {
        while (s.size() > k)
        {
            string t = "";
            for (int i = 0; i < s.size(); i += k)
            {
                int sum = 0;
                for (int j = 0; (j < k) and (i + j) < s.size(); j++)
                {
                    sum += s[i + j] - '0';
                }
                t += to_string(sum);
            }

            s = t;
        }

        return s;
    }
};