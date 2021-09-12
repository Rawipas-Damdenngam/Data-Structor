#include <iostream>
#include <list>
using namespace std;

#define NMAX 500

class Graph
{
    int V;
    list<int> *adj;
    bool isCyclicUtil(int v, bool visited[], bool *rs);  // used by isCyclic()

public:
    Graph(int V);
    void addEdge(int u, int v);
    bool isCyclic();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
}

bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false) // if not visited
    {
        visited[v] = true; // mark as visited
        recStack[v] = true; // mark as part of cycle
 
        // recur for all adjacent verticles
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if (!visited[*i] && isCyclicUtil(*i, visited, recStack)) // if the vertex is not visited, recursively calls the function until return (DFS from vertex v)
                return true;
            else if (recStack[*i]) // if the vertex is already in recur stack 
                return true;
        }
    }
    recStack[v] = false;  // clear recur stack
    return false;
}
 
bool Graph::isCyclic() // DFS
{
    bool *visited = new bool[V]; // visited = false
    bool *recStack = new bool[V]; // recur stack = false
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
 
    // check every vertex
    for(int i = 0; i < V; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;
    return false;
}

int main() {
    int n,e,start,end;
    cin >> n;
    Graph g(n);
    cin >> e;
    for (int i = 0; i < e; i++) {
        int from,to;
        cin >> from >> to;
        g.addEdge(from,to);
    }
    if (g.isCyclic()) {
        cout << "Graph contains cycle" << endl;
    } else {
        cout << "Graph doesn't contain cycle" << endl;
    }
    return 0;
}