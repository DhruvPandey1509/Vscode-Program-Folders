#include <iostream>
#include <list> //doubly linked list from STL Library of C++
#include <queue>
using namespace std;

class Graph
{
    int V;
    list<int> *l; // pointer to array of list (Dynamic Memory Allocation)
    //could have also used vector<list<int>> l;
    
    public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    }
    /* To add the neighbour to the list*/
    void addEdge(int i, int j, bool undir = false)
    {
        l[i].push_back(j);
        if (undir)
        {
            l[j].push_back(i);
        }
    }

    void printAdjList()
    {
        // Iterate over all rows
        for (int i = 0; i < V; i++)
        {
            cout << i << "->";
            // every element of ith linked list
            for (auto node : l[i])
            {
                cout << node << ",";
            }

            cout << endl;
        }
    }
    void bfs(int source)
    {
        queue<int> q;
        bool *visited = new bool[V]{0}; // initialising it with 0 i.e false

        q.push(source);
        visited[source] = true;

        while (!q.empty())
        {
            int f = q.front();
            cout << f << " ";

            q.pop();

            // push the nbrs of the current node inside q if they are not already visited
            for (auto nbr : l[f])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
    void dfsHelper(int node, bool *visited)
    {
        visited[node] = true;
        cout << node << ",";
        // make a dfs call on all its unvisited neighbours
        for (int nbr : l[node])
        {
            if (!visited[nbr])
            {
                dfsHelper(nbr, visited);
            }
            return;
        }
    }
    void dfs(int source)
    {
        bool *visited = new bool[V]{0};
        dfsHelper(source, visited);
    }

    void topological_sort() // for directed graphs only
    {
        vector<int> indegree(V, 0);

        // iterate over all the edges to find the right indegree
        for (int i = 0; i < V; i++)
        {
            for (auto nbr : l[i])
            {
                indegree[nbr]++;
            }
        }

        // bfs
        queue<int> q;
        // init the q with nodes having 0 indegree
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // start popping nodes
        while (!q.empty())
        {
            int node = q.front();
            cout << node << " ";
            q.pop();

            // iterate over the nbrs of this node and reduce their indegree by 1
            for (auto nbr : l[node])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
    }
};
