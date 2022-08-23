#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int countPalindrome(string s, int l1, int r1, int n)
    {
        int count = 0;
        while (l1 >= 0 and r1 < n and (s[l1] == s[r1]))
        {
            l1--;
            r1++;
            count++;
        }
        return count;
    }
    int countSubstrings(string s)
    {
        int count = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            count += countPalindrome(s, i, i, n);     // odd length
            count += countPalindrome(s, i, i + 1, n); // even length
        }

        return count;
    }
};