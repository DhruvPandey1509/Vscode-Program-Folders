#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
    {

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (auto i : edges)
        {
            dist[i[0]][i[1]] = i[2];
            dist[i[1]][i[0]] = i[2];
        }

        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                        continue;

                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int count_city = n;
        int city_no = -1;

        for (int city = 0; city < n; city++)
        {
            int count = 0;
            for (int adj_city = 0; adj_city < n; adj_city++)
            {
                if (dist[city][adj_city] <= distanceThreshold)
                    count++;
            }
            if (count <= count_city)
            {
                count_city = count;
                city_no = city;
            }
        }

        return city_no;
    }
};
