#include "bits/stdc++.h"
using namespace std;

#define n 256
int isPossible(string s)
{
    vector<int> freq(n, 0);

    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i]]++;
    }
    int odd = 0;
    for (int i = 0; i < n; i++)
    {
        if (freq[i] % 2 != 0)
        {
            odd++;
        }

        if (odd > 1)
            return 0;
    }

    return 1;
}