#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int j = 0;

        for (int i = 0; i < haystack.size();)
        {
            if (haystack[i] == needle[j])
            {
                j++;
                i++;

                if (j == needle.size())
                {
                    return i - needle.size();
                }
            }

            else
            {
                i = i - j + 1;
                j = 0;
            }
        }

        return -1;
    }
};