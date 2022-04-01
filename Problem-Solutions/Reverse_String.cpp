#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    void swap(char *a, char *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void reverseString(vector<char> &s)
    {
        // reverse(s.begin(), s.end());
        for (int i = 0; i < s.size() / 2; i++)
        {
            swap(&s[i], &s[s.size() - 1 - i]);
        }
    }
};