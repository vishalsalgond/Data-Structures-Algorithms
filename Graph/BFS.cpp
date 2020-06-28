#include <bits/stdc++.h>
using namespace std;

//assuming all vertices are reachable
class Graph{

    int V;
    list<int> *adj;

public:

    Graph(int V);

    void addEdge(int v,int w);

    void BFS(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::BFS(int s){

    bool *vis = new bool[V];
    for(int i = 0; i < V; i++) 
        vis[i] = false; 

    queue <int> Q;
    vis[s] = true;

    Q.push(s);

    while(!Q.empty()){
        s = Q.front();
        cout << s << " ";
        Q.pop();

        for(auto it=adj[s].begin(); it!=adj[s].end(); it++ ){
            
            if(!vis[*it]){
                vis[*it]=true;
                Q.push(*it);
            }
        }
    }
}

int main(){
    
    Graph g(5);
    
    //add vertices with values < V
    g.addEdge(1, 2); 
    g.addEdge(2, 1); 
    g.addEdge(2, 3); 
    g.addEdge(2, 4); 
    g.addEdge(4, 3); 
    g.addEdge(3, 1); 
    g.addEdge(2, 0);
  
    
    g.BFS(1);

    return 0;
}

//Time Complexity: O(V+E) where V is number of vertices in the graph and E is number of edges in the graph.
