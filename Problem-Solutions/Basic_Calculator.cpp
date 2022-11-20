#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        int res = 0, n = s.size(), sign = 1, sum = 0;
        stack<int> st, operation;

        for (int i = 0; i < n; i++)
        {
            if (isdigit(s[i]))
            {
                int num = s[i] - '0';
                while (i + 1 < n && isdigit(s[i + 1]))
                {
                    num = num * 10 + (s[i + 1] - '0');
                    i++;
                }
                res += num * sign;
            }
            else if (s[i] == '+')
                sign = 1;
            else if (s[i] == '-')
                sign = -1;
            else if (s[i] == '(')
            {
                st.push(res);
                operation.push(sign);
                res = 0;
                sign = 1;
            }
            else if (s[i] == ')')
            {
                res = res * operation.top();
                operation.pop();
                res += st.top();
                st.pop();
            }
        }
        return res;
    }
};