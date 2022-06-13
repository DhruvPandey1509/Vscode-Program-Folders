#include "bits/stdc++.h"
using namespace std;

void util(vector<int> graph[], bool isVisited[], stack<int> &st, int i)
{
    isVisited[i] = true;
    int n = graph[i].size();
    for (int j = 0; j < n; j++)
    {
        if (!isVisited[graph[i][j]])
        {
            util(graph, isVisited, st, graph[i][j]);
        }
    }
    st.push(i);
}

void topologicalSort(vector<int> graph[], int V)
{
    bool isVisited[V];
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!isVisited[i])
        {
            util(graph, isVisited, st, i);
        }
    }

    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
}

int main()
{
    int V, E, s, d;
    cin >> V >> E;

    vector<int> graph[V];

    for (int i = 0; i < E; i++)
    {
        cin >> s >> d;
        graph[s].push_back(d);
    }

    topologicalSort(graph, V);

    return 0;
}