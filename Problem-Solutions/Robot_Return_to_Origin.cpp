#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool judgeCircle(string moves)
    {
        unordered_map<char, int> m;
        for (char c : moves)
        {
            m[c]++;
        }
        for (auto i : m)
        {
            if (i.first == 'L')
            {
                if (m.find('R') == m.end())
                    return false;

                if (m['L'] != m['R'])
                    return false;
            }
            else if (i.first == 'R')
            {
                if (m.find('L') == m.end())
                    return false;

                if (m['R'] != m['L'])
                    return false;
            }
            else if (i.first == 'U')
            {
                if (m.find('D') == m.end())
                    return false;

                if (m['U'] != m['D'])
                    return false;
            }
            else if (i.first == 'D')
            {
                if (m.find('U') == m.end())
                    return false;

                if (m['D'] != m['U'])
                    return false;
            }
        }
        return true;
    }
};