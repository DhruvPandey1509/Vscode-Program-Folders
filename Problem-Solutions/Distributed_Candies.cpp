#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        set<int> s;

        for (int i = 0; i < candyType.size(); i++)
        {
            s.insert(candyType[i]);
        }

        int count = s.size();

        if (count > candyType.size() / 2)
        {
            return candyType.size() / 2;
        }
        else
        {
            return count;
        }
    }
};