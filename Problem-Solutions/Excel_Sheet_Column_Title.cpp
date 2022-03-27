#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    string convertToTitle(int num)
    {

        string res = "";
        while (num)
        {
            char last = (num - 1) % 26 + int('A');
            res = last + res;
            num = (num - 1) / 26;
        }
        return res;
    }
};