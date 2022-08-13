#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int numMagicSquaresInside(vector<vector<int>> &g)
    {
        int n = g.size();
        int m = g[0].size();

        if (n < 3 || m < 3)
            return 0;

        int count = 0;
        int r1, r2, r3, c1, c2, c3, d1, d2;
        int r, c, d;
        for (int i = 0; i < n; i++)
        {
            if (i + 2 >= n)
                break;
            for (int j = 0; j < m; j++)
            {
                if (j + 2 >= m)
                    break;

                // each row sum of 3*3 matrix whose top left cell=(i,j)
                r1 = g[i][j] + g[i][j + 1] + g[i][j + 2];
                r2 = g[i + 1][j] + g[i + 1][j + 1] + g[i + 1][j + 2];
                r3 = g[i + 2][j] + g[i + 2][j + 1] + g[i + 2][j + 2];

                // each column sum of 3*3 matrix whose top left cell=(i,j)

                c1 = g[i][j] + g[i + 1][j] + g[i + 2][j];
                c2 = g[i][j + 1] + g[i + 1][j + 1] + g[i + 2][j + 1];
                c3 = g[i][j + 2] + g[i + 1][j + 2] + g[i + 2][j + 2];

                // diagonal sum
                d1 = g[i][j] + g[i + 1][j + 1] + g[i + 2][j + 2];
                d2 = g[i][j + 2] + g[i + 1][j + 1] + g[i + 2][j];

                // checking sum equality

                bool f = false;
                if ((r1 == r2) && (r1 == r3) && (r1 == c1) && (r1 == c2) && (r1 == c3) && (r1 == d1) && (r1 == d2))
                    f = true;
                else
                    continue;

                // checking duplicacy of no's and range of no's [1,9]

                set<int> st;

                for (int k1 = i; k1 <= i + 2; k1++)
                {
                    for (int k2 = j; k2 <= j + 2; k2++)
                    {
                        if (g[k1][k2] > 9 || g[k1][k2] == 0)
                        {
                            f = false;
                            break;
                        }
                        st.insert(g[k1][k2]);
                    }
                    if (f == false)
                        break;
                }

                if (f && (st.size() == 9))
                    count++;
            }
        }
        return count;
    }
};