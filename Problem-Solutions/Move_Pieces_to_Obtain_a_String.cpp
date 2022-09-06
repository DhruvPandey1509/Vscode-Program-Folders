#include "bits/stdc++.h"
using namespace std;

// 1.) for all R and L in target there should be a corresponding R and L in start also.Means The relative order of L/R in start and target should be same.Becoz we cant move L beyond a R or R beyond a L.
// 2.) for every R and L in Target, the corresponding R/L in start can be
// a) Corresponding L can be ahead in start, becoz we can always bring it to left and make position equal to that of in target.
// b) Corresponding R can be behind in start, becoz we can always bring it to right and make position equal to that of in target.
// else Answer will be NO
// So, save all chars and their position from start in a vector, and for every element L/R in target,check for above two condition if it satisfies
// we are good to go else Answer will be NO.
class Solution
{
public:
    bool canChange(string start, string target)
    {
        vector<pair<char, int>> v;

        for (int i = 0; i < start.size(); i++)
        {
            if (start[i] != '_')
            {
                v.push_back({start[i], i});
            }
        }

        int i = 0;
        for (int j = 0; j < target.size(); j++)
        {
            if (target[j] != '_')
            {
                if (i >= v.size() || v[i].first != target[j])
                    return false;
                else
                {
                    if (v[i].first == 'L' and v[i].second < j)
                        return false;
                    if (v[i].first == 'R' and v[i].second > j)
                        return false;

                    i++;
                }
            }
        }

        return i == v.size();
    }
};