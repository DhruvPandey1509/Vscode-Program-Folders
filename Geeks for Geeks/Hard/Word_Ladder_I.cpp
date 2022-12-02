#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
    {
        unordered_set<string> s(wordList.begin(), wordList.end());
        s.erase(startWord);

        queue<pair<string, int>> q;
        q.push({startWord, 1});

        while (!q.empty())
        {
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            if (word == targetWord)
                return level;

            for (int i = 0; i < word.size(); i++)
            {
                char org = word[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;
                    if (s.find(word) != s.end())
                    {
                        s.erase(word);
                        q.push({word, level + 1});
                    }
                }
                word[i] = org;
            }
        }

        return 0;
    }
};
