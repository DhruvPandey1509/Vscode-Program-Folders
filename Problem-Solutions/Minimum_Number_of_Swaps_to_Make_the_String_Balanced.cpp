#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minSwaps(string s)
    {
        int extra_closing = 0;
        int max_closing = INT_MIN;

        for (char c : s)
        {
            if (c == ']') // for closing ] we will increase it by 1
                extra_closing++;
            else
                extra_closing--; // for opening [ we will decrease it by 1

            max_closing = max(max_closing, extra_closing); // max will tell how many closing bracket were there at a moment that needs to be dealt with
        }

        if (max_closing <= 0)
            return 0;

        return (max_closing + 1) / 2; // with each swap two brackets are dealt
    }
};
