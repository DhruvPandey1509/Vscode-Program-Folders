#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    /*
        In Step 1 : We maintained a universal array to store the maximum count of every letter in every string of 
        *words2  with helper function*

        In Step 2 : We checked for every string in words1 that , if frequency of any character is less than the 
        count in universal array , then that string is not valid as per our requirements .
    */
    unordered_map<char, int> helper(string words)
    {
        unordered_map<char, int> m;
        for (auto i : words)
        {
            m[i]++;
        }
        return m;
    }
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        unordered_map<char, int> map;
        for (auto i : words2)
        {
            unordered_map<char, int> temp = helper(i);
            for (auto j : temp)
            {
                map[j.first] = max(j.second, map[j.first]);
            }
        }

        vector<string> res;
        for (auto i : words1)
        {
            unordered_map<char, int> word = helper(i);
            bool flag = true;
            for (auto j : map)
            {
                if (j.second > word[j.first])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                res.push_back(i);
        }

        return res;
    }
};