#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string pushDominoes(string d)
    {
        int n = d.size();
        int r = -1;

        for (int i = 0; i < n; i++)
        {
            if (d[i] == 'L')
            {
                if (r == -1)
                {
                    for (int j = i - 1; j >= 0 and d[j] == '.'; j--)
                    {
                        d[j] = 'L';
                    }
                }
                else
                {
                    for (int j = r + 1, k = i - 1; j < k; j++, k--)
                    {
                        d[j] = 'R';
                        d[k] = 'L';
                    }
                }
                r = -1;
            }
            else if (d[i] == 'R')
            {
                if (r != -1)
                {
                    for (int j = r + 1; j < i; j++)
                    {
                        d[j] = 'R';
                    }
                }
                r = i;
            }
        }

        if (r != -1)
        {
            for (int j = r + 1; j < n; j++)
            {
                d[j] = 'R';
            }
        }

        return d;
    }
};