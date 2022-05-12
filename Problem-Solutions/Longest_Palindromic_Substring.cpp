#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        string res = "";
        int len = INT_MIN;
        int left = -1;
        int right = -1;
        for (int i = 0; i < s.length(); i++)
        {
            // odd length palindrome
            int l1 = i, r1 = i;
            while (l1 >= 0 && r1 < s.length() and s[l1] == s[r1])
            {
                if (r1 - l1 + 1 > len)
                {
                    right = r1;
                    left = l1;
                    len = r1 - l1 + 1;
                }
                l1 -= 1;
                r1 += 1;
            }
            // even length palindrome
            int l2 = i, r2 = i + 1;
            while (l2 >= 0 && r2 < s.length() and s[l2] == s[r2])
            {
                if (r2 - l2 + 1 > len)
                {
                    right = r2;
                    left = l2;
                    len = r2 - l2 + 1;
                }
                l2 -= 1;
                r2 += 1;
            }
        }

        return s.substr(left, right - left + 1);
    }
};