//https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/?track=ppc-graph&batchId=221

/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool cyclicUtil(int v, bool visited[], 
                bool *recStack, vector<int> adj[]){
    
    visited[v] = true;
    recStack[v] = true;
    
    for(int m : adj[v]){
        
        //if not visited and isCyclic
        if(!visited[m]){
            if(cyclicUtil(m, visited, recStack, adj)){
                return true;
            }
        }
        //if already visited and in recStack
        if(recStack[m]) return true;
    }
    
    recStack[v] = false; //remove vertex from recStack
    return false;
    
}

bool isCyclic(int V, vector<int> adj[])
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
            if (cyclicUtil(i, visited, recStack, adj)){
                return true;
            }
        }
    }
    
    return false;
}

//Time Complexity: O(V + E)
//Auxiliary Space: O(V)
