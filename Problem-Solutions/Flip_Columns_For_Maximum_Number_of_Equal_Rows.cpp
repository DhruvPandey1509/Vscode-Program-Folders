#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        unordered_map<string, int> m;
        for (auto &it : matrix)
        {
            string s(it.size(), 'T');
            cout << it.size() << endl;
            for (int i = 1; i < it.size(); i++)
            {
                cout << it[0] << " : " << it[i] << endl;
                if (it[0] != it[i])
                    s[i] = 'F';
            }
            m[s]++;
        }
        int ans;
        for (auto &it : m)
            ans = max(ans, it.second);
        return ans;
    }
};
