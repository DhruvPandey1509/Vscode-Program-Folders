#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
using namespace std;

class Node
{
    public:
    string name;
    list<string> nbrs;// list of neighbours
     
    Node(string name)
    {
        this->name = name;
    }
};
 
class Graph
{
    //All Nodes
    //Hasmap(string, Node*)
    
    unordered_map<string, Node*> m;
    public:
    Graph(vector<string> cities)
    {
        for(auto city : cities)
        {
            m[city] = new Node(city);
        }
    }

    void addEdge(string x, string y, bool undir=false)
    {
        m[x]->nbrs.push_back(y); //adding the neighbours in the list that in in the node
        if(undir)//if undirected graph
        {
            m[y]->nbrs.push_back(x);
        }
    }

    void printAdjList()
    {
        for(auto cityPair : m)
        {
           auto city = cityPair.first;
           Node *node = cityPair.second; 
           cout<<city<<"->"; 
           for(auto nbr : node->nbrs)
           {
               cout<<nbr<<",";
           }
           cout<<endl;
        }
    }
};