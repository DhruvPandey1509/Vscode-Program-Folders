#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int divisorSubstrings(int num, int k)
    {

        string s = to_string(num);

        if (s.size() == 1)
        {
            return 1;
        }

        int count = 0;
        for (int i = 0; i <= s.length() - k; i++)
        {
            int n1 = stoi(s.substr(i, k));
            if (n1 == 0)
                continue;
            if (num % n1 == 0)
                count++;
        }

        return count;
    }
};