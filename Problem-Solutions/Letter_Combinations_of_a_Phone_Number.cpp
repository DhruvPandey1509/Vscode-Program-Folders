#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<string> res;
    vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void solution(int i, string curr, string digits)
    {
        if (curr.length() == digits.length())
        {
            res.push_back(curr);
            return;
        }

        for (char c : v[digits[i] - '0'])
        {
            solution(i + 1, curr + c, digits);
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.length() != 0)
        {
            solution(0, "", digits);
        }

        return res;
    }
};