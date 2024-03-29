#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int rows = bank.size();
        if (rows == 1)
            return 0;

        vector<int> v;
        for (int i = 0; i < rows; i++)
        {
            int count = 0;
            string s = bank[i];
            for (char c : s)
            {
                if (c == '1')
                    count++;
            }
            if (count > 0)
                v.push_back(count);
        }

        if (v.size() == 0 || v.size() == 1)
            return 0;

        int res = 0;
        for (int i = 0; i < v.size() - 1; i++)
        {
            res += v[i] * v[i + 1];
        }

        return res;
    }
};