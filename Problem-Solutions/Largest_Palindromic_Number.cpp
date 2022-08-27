#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string largestPalindromic(string num)
    {
        vector<int> freq(10);

        for (char c : num)
        {
            freq[c - '0']++;
        }

        string front = "", back = "";

        for (int i = 9; i >= 0; i--)
        {
            if (i == 0 and front.empty())
                continue;

            while (freq[i] > 1)
            {
                front += to_string(i);
                back += to_string(i);
                freq[i] -= 2;
            }
        }

        for (int i = 9; i >= 0; i--)
        {
            if (freq[i])
            {
                front += to_string(i);
                break;
            }
        }

        reverse(back.begin(), back.end());
        return front + back;
    }
};