//https://practice.geeksforgeeks.org/problems/topological-sort/1

// The Graph structure is as folows

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*/
void dfs(vector<int> adj[], int v, 
        vector <int> &topo, bool visited[]){
            
    visited[v] = true;
    
    for(int j : adj[v]){
        if(!visited[j]){
            dfs(adj,j,topo,visited);
        }
    }
    
    topo.push_back(v);
    
}

vector<int> topoSort(int V, vector<int> adj[]) {
    bool *visited = new bool[V];
    vector <int> topo;
    
    for(int i = 0; i < V; i++)
        visited[i] = false;

    for(int i = 0; i < V; i++){
        if(!visited[i])
            dfs(adj, i, topo, visited);
    }
    
    reverse(topo.begin(), topo.end());
    return topo;
}
