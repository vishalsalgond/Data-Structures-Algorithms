//https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/?track=ppc-graph&batchId=221

/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/
bool cyclicUtil(int v, bool visited[], 
                bool *recStack, vector<int> adj[], int parent){
    
    visited[v] = true;
    recStack[v] = true;
    
    for(int m : adj[v]){
        
        //if not visited and isCyclic
        if(!visited[m]){
            if(cyclicUtil(m, visited, recStack, adj, v)){
                return true;
            }
        }
        //if already visited and in recStack
        if(recStack[m] && m!=parent) return true;
    }
    
    recStack[v] = false; //remove vertex from recStack
    return false;
    
}

bool isCyclic(vector<int> adj[], int V)
{
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    
    for(int i = 0; i < V; i++){
        visited[i] = false;
        recStack[i] = false;
    }
    
    //check for each vertex
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            if (cyclicUtil(i, visited, recStack, adj, -1)){
                return true;
            }
        }
    }
    
    return false;
}
