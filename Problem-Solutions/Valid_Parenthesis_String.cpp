#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<int> open, star;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '*')
            {
                star.push(i);
            }
            else if (s[i] == '(')
            {
                open.push(i);
            }
            else
            {
                if (!open.empty())
                {
                    open.pop();
                }
                else if (!star.empty())
                {
                    star.pop();
                }
                else
                    return false;
            }
        }

        while (!open.empty())
        {
            if (star.empty())
                return false;
            else if (open.top() < star.top())
            {
                open.pop();
                star.pop();
            }
            else // open.top() > start.top();
                return false;
        }
        return true;
    }
};
