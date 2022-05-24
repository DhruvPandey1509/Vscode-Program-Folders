#include<iostream>
#include"adjacent_list.h"
using namespace std;

int main()
{
    Graph g(6);
    g.addEdge(0,2);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.addEdge(2,3); 
    g.addEdge(1,4);
    g.addEdge(1,2);

    g.printAdjList();
    // g.bfs(1);
    cout<<endl;
    // g.dfs(1);
    // cout<<endl;

    g.topological_sort();

    return 0;
}