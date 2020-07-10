#include <iostream>
#include <list>
using namespace std;

void addEdge(list<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

/**
 * Algorithm of Depth First Search is even more simple than BFS
 *      Populate a boolean array visited and set it all to zero
 *      Iterate over every node of adjacency list of starting node
 *          For every node check if its already visited, if yes continue to next node
 *          If not, set node in visited array to true.
 *          Recursively repeat the same process this time with adjacency list of current node
 * 
 * Please note that in BFS we visit adjacent nodes first(horizontal) and then go to next level(vertical)
 * In DFS we first go deep till last node(vertical) and then adjacent nodes (horizontal)
 * 
 * Running Time : O(V+E)    
 */
void dfsUtil(list<int> adj[], int v, bool visited[])
{
    cout<<v<<" : DONE"<<endl;
    visited[v] = true;
    list<int>::iterator it;
    for(it = adj[v].begin(); it != adj[v].end(); ++it)
    {
        if(!visited[*it])
            dfsUtil(adj, *it, visited);
    }
}

void dfs(list<int> adj[], int n, int start)
{
    bool visited[n];
    for(int i = 0; i<n; ++i)
        visited[i]=false;
    
    dfsUtil(adj, start, visited);
}

int main()
{
    cout<<"DFS"<<endl;

    int n = 5;
    list<int> adj[n];
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,4,1);
    addEdge(adj,2,4);

    dfs(adj, n, 0);
}