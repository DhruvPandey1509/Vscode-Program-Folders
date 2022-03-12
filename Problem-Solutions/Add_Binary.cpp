#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    string addBinary(string a, string b)
    {
        int n1 = a.length() - 1, n2 = b.length() - 1;
        string res;
        int carry = 0;

        while (n1 >= 0 || n2 >= 0)
        {
            int sum = 0;
            if (n1 >= 0)
            {
                sum += (a[n1] - '0'); // when you subtract the '0' character from another character that represents a digit,
                n1--;                 // you get the numerical value of that digit
            }
            if (n2 >= 0)
            {
                sum += (b[n2] - '0'); // converting string to int as expained above
                n2--;
            }

            sum += carry;
            res += to_string(sum % 2); // converting int type to string type
            if (sum > 1)
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }
        }

        if (carry)
        {
            res += '1';
        }

        reverse(res.begin(), res.end()); // reversing the string
        return res;
    }
};