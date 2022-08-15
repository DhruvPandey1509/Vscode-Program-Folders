#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {

        int i = 0, j = 0, k = 0;
        string res = "";
        bool flag = true;
        while (i < word1.size() and j < word2.size())
        {
            if (flag)
            {
                res += word1[i];
                i++;
            }
            else
            {
                res += word2[j];
                j++;
            }
            k++;
            flag = !flag;
        }

        while (i < word1.size())
        {
            res += word1[i];
            i++;
            k++;
        }
        while (j < word2.size())
        {
            res += word2[j];
            j++;
            k++;
        }

        return res;
    }
};