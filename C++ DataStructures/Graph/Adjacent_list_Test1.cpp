#include<iostream>
#include"adjacent_list_string.h"
using namespace std; 

int main()
{
    vector<string> cities = {"Delhi", "London", "Paris", "New York"};
    Graph g(cities);

    g.addEdge("Delhi","London");
    g.addEdge("New York","London");
    g.addEdge("Delhi","Paris");
    g.addEdge("Paris","New York");

    g.printAdjList(); 

    return 0;
}