#include <bits/stdc++.h>
using namespace std;

//assuming all vertices are reachable
class Graph{

    int V;
    list<int> *adj;
    bool *vis;
public:

    Graph(int V);

    void addEdge(int v,int w);

    void DFS(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
    vis = new bool[V];
    for(int i = 0; i < V; i++) 
        vis[i] = false; 
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::DFS(int s){

    vis[s] = true;
    cout << s << " ";

    for(auto it = adj[s].begin(); it! = adj[s].end(); it++ ){
            
        if(!vis[*it]){
            DFS(*it);
        }
    }
}


int main(){
    
    //add vertices with values < V
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    
    g.DFS(2);

    return 0;
}

// Time complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
// Space Complexity: O(V).
// Since, an extra visited array is needed of size V.
