#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minMutation(string start, string end, vector<string> &bank)
    {
        queue<string> q;
        unordered_set<string> visited;
        int count = 0;
        q.push(start);
        visited.insert(start);

        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                string node = q.front();
                q.pop();
                if (node == end)
                {
                    return count;
                }

                for (char ch : "ACGT")
                {
                    for (int j = 0; j < node.size(); j++)
                    {
                        string adjnode = node;
                        adjnode[j] = ch;
                        if (!visited.count(adjnode) and find(bank.begin(), bank.end(), adjnode) != bank.end())
                        {
                            q.push(adjnode);
                            visited.insert(adjnode);
                        }
                    }
                }
            }
            count++;
        }

        return -1;
    }
};
