#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minimumMoves(string s)
    {
        int moves = 0;
        int i = 0;

        while (i < s.size())
        {
            if (s[i] == 'O')
            {
                i += 1;
            }
            else
            {
                moves += 1;
                i += 3;
            }
        }

        return moves;
    }
};