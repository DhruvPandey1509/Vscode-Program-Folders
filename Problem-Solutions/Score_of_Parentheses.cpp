#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int scoreOfParentheses(string s)
    {

        int depth = 0, count = 0;
        char prev = '(';

        for (auto ch : s)
        {
            if (ch == '(')
            {
                depth++;
            }
            else
            {
                depth--;
                if (prev == '(')
                {
                    count += pow(2, depth);
                }
            }

            prev = ch;
        }

        return count;
    }
};