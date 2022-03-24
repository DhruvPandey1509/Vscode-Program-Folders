#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {

        if (s.size() == 0 && t.size() == 0)
        {
            return true;
        }

        else if (s.size() == 0)
        {
            return true;
        }

        else if (t.size() == 0)
        {
            return false;
        }

        int n1 = s.size();
        int n2 = t.size();
        int count = n1; // keep track of how many words are left in string

        int i = 0;
        int j = 0;
        while (i < n1 && j < n2)
        {
            while (j < n2)
            {
                if (s[i] == t[j])
                {
                    count--;
                    i++;
                }
                j++;
            }
        }

        if (count == 0)
        {
            return true;
        }

        return false;
    }
};

class Solution1
{
public:
    bool isSubsequence(string s, string t)
    {
        int i = 0, j = 0;
        int n1 = s.length(), n2 = t.length();

        while (i < n1 && j < n2)
        {
            if (s[i] == t[j])
            {
                i++;
            }
            j++;
        }

        if (i == n1) // if the iterator of s is of its length that means s is subsequence of t;
        {
            return true;
        }

        return false;
    }
};