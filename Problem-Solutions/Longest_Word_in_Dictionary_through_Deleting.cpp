#include "bits/stdc++.h"
using namespace std;
// Iterate the dictionary and at each iteration check if d[i] is present within input string s, using the two-pointer approach.
// If d[i] is present completely within s:
// Then check if the length of the curr string is greater than our ans string, if so update ans, that is ans = curr.
// Also, if the length of curr string is equal to ans and curr is lexicographically smaller than ans, then update ans with curr, that is ans=curr.
// Considering m = length of input string s and
// n = size of dictionary vector.

// TIME COMPLEXITY
// O(mn)

// SPACE COMPLEXITY
// O(1)

class Solution
{
public:
    string findLongestWord(string s, vector<string> &d)
    {
        int n = d.size();
        int m = s.size();

        string res = "";

        for (int i = 0; i < n; i++)
        {
            // checking weather d[i] is present within "s" using two pointer approach
            string curr = d[i];
            int a = 0, b = 0;

            int count = 0; // counting character and matching it with the size of current word

            while (a < m and b < curr.size())
            {
                if (s[a] == curr[b])
                {
                    count++;
                    b++;
                }
                a++;
            }

            // current word is present in s
            if (count == curr.size())
            {
                // check whether "curr" is longer than "ans"
                // OR
                // if "curr" and "ans" are same length then choose the lexicographically smaller one
                if (res.size() < curr.size() || (res.size() == curr.size() and curr < res))
                {
                    res = curr;
                }
            }
        }

        return res;
    }
};
