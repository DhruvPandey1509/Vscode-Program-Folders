#include "bits/stdc++.h"
using namespace std;

typedef vector<pair<int, pair<int, int>>> viii;

int find(int u, int parent[])
{
    if (parent[u] < 0)
    {
        return u;
    }

    return find(parent[u], parent);
}

void unionByWeight(int u, int v, int parent[])
{
    int pu = find(u, parent);
    int pv = find(v, parent);
    if (pu != pv)
    {
        if (parent[pu] < parent[pv])
        {
            parent[pu] += parent[pv];
            parent[pv] = pu;
        }
        else
        {
            parent[pv] += parent[pu];
            parent[pu] = pv;
        }
    }
}

viii kruskals(viii g, int V)
{
    viii res;
    int s, d, w;

    int parent[V];

    for (int i = 0; i < V; i++)
    {
        parent[i] = -1;
    }

    sort(g.begin(), g.end());
    int E = g.size();
    for (int i = 0; i < E; i++)
    {
        s = g[i].second.first;
        d = g[i].second.second;

        w = g[i].first;

        if (find(s, parent) != find(d, parent))
        {
            res.push_back(g[i]);
            unionByWeight(s, d, parent);
        }
    }

    return res;
}

int main()
{
    viii g, res;
    int V, E, s, d, w;

    cin >> V >> E;

    for (int i = 0; i < E; i++)
    {
        cin >> s >> d >> w;
        g.push_back({w, {s, d}});
    }

    res = kruskals(g, V);
    int sum = 0;

    for (int i = 0; i < res.size(); i++)
    {
        int w = res[i].first;
        cout << res[i].second.first << " " << res[i].second.second << endl;
        sum += w;
    }

    cout << "Sum of Weights : " << sum << endl;

    return 0;
}