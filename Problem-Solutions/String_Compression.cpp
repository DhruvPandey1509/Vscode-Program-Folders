#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int i = 0, idx = 0;
        int n = chars.size();
        while (i < n)
        {
            int j = i;
            while (j < n and chars[j] == chars[i])
            {
                j++;
            }
            chars[idx++] = chars[i];
            if (j - i > 1)
            {
                string temp = to_string(j - i);
                for (char c : temp)
                {
                    chars[idx++] = c;
                }
            }
            i = j;
        }

        return idx;
    }
};