#include <iostream>
#include <list>

using namespace std;

/*
    Graph is a non-linear data structure which consists of nodes/vertices and edges
    Two commonly used representations of graph :-
    1. Adjacency List
    2. Adjacency Matrix
*/

void addEdge(list<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(list<int> adj[], int n)
{
    for(int i = 0; i<n; ++i)
    {
        cout<<"Adjacency list of vertex "<<i<<" : \n head ";
        list<int>::iterator it;
        for(it = adj[i].begin(); it!= adj[i].end(); ++it)
        {
            cout<<" -> "<<*it;
        }
        cout<<endl;
    }
}

bool isEdgePresent(list<int> adj[], int u, int v)
{
    for(int i : adj[u])
    {
        if(i == v)
            return true;
    }

    return false;
}

int main()
{
    int n = 5;
    list<int> adj[n];
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,4,1);
    addEdge(adj,2,4);
    printGraph(adj,n);

    cout<<isEdgePresent(adj,1, 3)<<endl;
    cout<<isEdgePresent(adj,0, 4)<<endl;
    cout<<isEdgePresent(adj,2,3)<<endl;
}