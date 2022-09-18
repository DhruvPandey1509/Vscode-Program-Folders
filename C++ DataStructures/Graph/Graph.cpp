#include "bits/stdc++.h"
using namespace std;
void bfs(unordered_map<int, vector<int>> m, int start = 3)
{
    queue<int> q;
    map<int, bool> visited;

    q.push(start);
    visited[start] = true;
    int count = 0;
    while (!q.empty())
    {
        int node = q.front();
        cout << node << " ";
        q.pop();
        bool flag = false;
        for (auto i : m[node])
        {
            if (!visited[i])
            {
                visited[i] = true;
                flag = true;
                q.push(i);
            }
        }
        if (flag)
            count++;
    }
    cout << endl;
    cout << count << endl;
}
int main()
{
    int n; // nodes
    cin >> n;
    unordered_map<int, vector<int>> m;
    while (1)
    {
        int u, v;
        cin >> u >> v;
        if (u == -1)
            break;
        m[u].push_back(v);
        m[v].push_back(u);
    }

    for (auto i : m)
    {
        cout << i.first << " : ";
        for (auto v : i.second)
        {
            cout << v << " ";
        }
        cout << endl;
    }
    bfs(m, 3);
    return 0;
}