#include <iostream> 
#include <vector> 
#include <stack> 
#include <queue> 
#include <algorithm> 

using namespace std; 
 
class Graph { 
    private: 
        int v; 
        vector<int> *adj; 
 
    public: 
        Graph(int v) { 
            this->v = v; 
            adj = new vector<int> [v]; 
        } 
 
        void addEdge(int u, int v) { 
            adj[u].push_back(v); 
            adj[v].push_back(u); 
            sort(adj[u].begin(), adj[u].end()); 
            sort(adj[v].begin(), adj[v].end()); 
        } 
 
        void printShortestPath(int src, int dest); 
        bool BFS(int src, int dest, int parent[]); 
}; 
 
void Graph::printShortestPath(int src, int dest) { 
 
    int parent[v]; 
 
    if(BFS(src, dest, parent) == false) { 
        cout << "Both towns are not connected" << endl; 
        return; 
    } 
 
    stack<int> st; 
 
    while(parent[dest] != -1) { 
        st.push(dest); 
        dest = parent[dest]; 
    } 
 
    cout << "Shortest road length is: " << st.size() << endl; 
    cout << "Road path: " << src; 
    while(!st.empty()) { 
        cout << " -> " << st.top(); 
        st.pop(); 
    } 
    return; 
} 
 
bool Graph::BFS(int src, int dest, int parent[]) { 
 
    queue<int> q; 
    bool visited[v]; 
 
    for(int i=0; i<v; i++) { 
        visited[i] = false; 
        parent[i] = -1; 
    } 
 
 
    q.push(src); 
    visited[src] = true; 
 
    while(!q.empty()) { 
  
        int temp = q.front(); 
        q.pop(); 
 
        for(int k: adj[temp]) { 
            if(visited[k] == false) { 
          
                q.push(k); 
                visited[k] = true; 
                parent[k] = temp; 
 
                 
                if(k == dest) 
                    return true; 
            } 
        } 
    } 
     
    return false; 
} 
 
 
int main() 
{ 
    int n,e,u,v; 
    cin >> n; 
    Graph g(n); 
    cin >> e; 
  
    while (e > 0) { 
        cin >> u >> v; 
        g.addEdge(u,v); 
        e--; 
    } 
    cin >> u >> v; 
    g.printShortestPath(u, v); 
    return 0; 
}