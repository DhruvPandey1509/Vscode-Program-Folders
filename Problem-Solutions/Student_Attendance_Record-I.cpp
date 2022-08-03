#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool checkRecord(string s)
    {
        int countA = 0;
        int countL = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'A')
            {
                countA++;
                countL = 0;
                if (countA >= 2)
                    return false;
            }
            else if (s[i] == 'L')
            {
                countL++;
                if (countL >= 3)
                    return false;
            }
            else
            {
                countL = 0;
            }
        }

        return true;
    }
};