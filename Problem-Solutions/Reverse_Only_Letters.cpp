#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        string str = "";

        for (int i = 0; i < s.size(); i++)
        {
            if ((s[i] >= 'a' and s[i] <= 'z') || (s[i] >= 'A' and s[i] <= 'Z'))
            {
                str += s[i];
            }
        }

        int j = str.size() - 1;
        for (int i = 0; i < s.size(); i++)
        {

            if (j >= 0 and (s[i] >= 'a' and s[i] <= 'z') || (s[i] >= 'A' and s[i] <= 'Z'))
            {
                s[i] = str[j];
                j--;
            }
        }

        return s;
    }
};