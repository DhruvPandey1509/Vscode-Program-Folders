#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int getMinSwaps(string num, int k)
    {
        string s = num;
        while (k--)
            next_permutation(s.begin(), s.end());

        int swap_count = 0;
        for (int i = 0; i < num.size(); ++i)
        {
            int j = i;
            while (num[i] != s[i])
            {
                ++swap_count;
                swap(s[i], s[++j]);
            }
        }
        return swap_count;
    }
};
