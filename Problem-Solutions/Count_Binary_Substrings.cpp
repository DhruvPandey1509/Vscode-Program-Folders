#include "bits/stdc++.h"
using namespace std;

// We need to create a group array which will tell us the group of 0s and 1s together
// After that we know the group of 0s and 1s so then we know that how many characters are consecutive and the minimum of the two would be
// would the consecutive strings we can make from them.

// Eg: [00011100]
// Group String: [3,3,2]
// min(3,3)=3 so it can be either 000111 or 111000 so from either of them we have 3 strings 01, 0011, 000111 OR similarly starting with 1
// min(3,2)=2 so it can be either 0011 or 1100 so from either of them we have 2 strings 01, 0011 OR similarly starting with 1
class Solution
{
public:
    int countBinarySubstrings(string s)
    {

        vector<int> v;
        int count = 0, res = 0;

        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] != s[i + 1])
            {
                v.push_back(count + 1);
                count = 0;
            }
            else
            {
                count++;
            }
        }

        // Put in the remaining last count into the array as well as it would have exited the loop before entering this one.
        v.push_back(count + 1);

        // Calculate the res as min of consecutive groups
        for (int i = 0; i < v.size() - 1; i++)
        {
            res += min(v[i], v[i + 1]);
        }

        return res;
    }
};