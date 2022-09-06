#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    unordered_map<char, int> m;
    bool checkOrder(string &a, string &b)
    {
        int i = 0;
        while (i < a.size() and i < b.size())
        {
            if (m[a[i]] != m[b[i]])
                return m[a[i]] < m[b[i]];
            i++;
        }

        return a.size() <= b.size();
    }

    bool isAlienSorted(vector<string> &words, string order)
    {

        for (int i = 0; i < order.size(); i++)
        {
            m[order[i]] = i;
        }

        for (int i = 0; i < words.size() - 1; i++)
        {
            if (!checkOrder(words[i], words[i + 1]))
                return false;
        }

        return true;
    }
};