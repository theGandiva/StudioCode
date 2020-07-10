#include <iostream>
#include <list>
using namespace std;

void addEdge(list<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

/**
 * Algorithm of bfs is pretty simple
 *      Populate a boolean array visited and set it all to zero
 *      Create a queue, put starting element there
 *      While queue is not empty
 *          print front element
 *          pop front element
 *          iterate over adjacency list for corresponding element
 *              if element in adjacency list is not visited
 *                  enqueue it in queue
 *                  set visited[v] = true
 * 
 * Please note bfs works fine to traverse a connected graph, for unconnected graph
 * we may have to iterate over all the vertices, check if they are visited or not, if not visited
 * perform bfs on every single one of them. 
 * 
 * Running Time : O(V+E)
 */
void bfs(list<int> adj[], int n, int start)
{
    bool visited[n];
    for(int i  = 0; i<n; ++i)
        visited[i] = false;

    list<int> queue;
    visited[start] = true;
    queue.push_back(start);

    list<int>::iterator it;

    // Iterate until queue is empty
    while(!queue.empty())
    {
        int x = queue.front();

        // Print the node
        cout<<x<<" : DONE"<<endl;

        // Dequeue node from queue
        queue.pop_front();

        // Push adjacency list of current node in queue
        for(it = adj[x].begin(); it != adj[x].end(); ++it)
        {
            if(!visited[*it])
            { 
                visited[*it] = true;
                queue.push_back(*it);
            }
        }
    }
}

int main()
{
    cout<<"BFS"<<endl;

    int n = 5;
    list<int> adj[n];
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,4,1);
    addEdge(adj,2,4);

    bfs(adj, n, 0);
}
