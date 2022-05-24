#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <set>
using namespace std;

class Graph
{
    int V;
    list<pair<int, int>> *l;

    public:
    Graph(int v)
    {
        V = v;
        l = new list<pair<int, int>>[V];
    }
    void addEdge(int u, int v, int wt, bool undir = true)
    {
        l[u].push_back({wt, v});
        if (undir)
        {
            l[v].push_back({wt, u});
        }
    }
    int dijkshtras(int src, int dest)
    {
        vector<int> dist(V, INT_MAX);
        set<pair<int, int>> s;

        // Initialisation
        dist[src] = 0;
        s.insert({0, src}); //' { } ' are used to make the pair inside else we could have used ' make_pair() '
        while (!s.empty())
        {
            auto it = s.begin();

            int distTillNow = it->first;
            int node = it->second;
            s.erase(it); // equivalent to pop operation

            // Iterate over the nbrs of the node
            for (auto nbrPair : l[node])
            {
                int currentEdge = nbrPair.first;
                int nbr = nbrPair.second;

                if (distTillNow + currentEdge < dist[nbr])
                {
                    // remove if nbr already exist in the set

                    auto f = s.find({dist[nbr], nbr});
                    if (f != s.end()) // it means it is present in the set
                    {
                        s.erase(f);
                    }
                    // insert the updated value with the new Distance
                    dist[nbr] = distTillNow + currentEdge;
                    s.insert({dist[nbr], nbr});
                }
            }
        }
        // Single Source SHortest Distance to all other nodes
        for (int i = 0; i < V; i++)
        {
            cout << "Node i : " << i << "\t Distance : " << dist[i] << endl;
        }
        return dist[dest];
    }
};
