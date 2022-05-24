#include <iostream>
#include "Dijkshtras_Algorithm.h"
using namespace std;

int main()
{
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 3, 7);
    g.addEdge(3, 2, 2);
    g.addEdge(3, 4, 3);

    cout << "Hello" << endl;

    cout << g.dijkshtras(0, 4) << endl;
}