#include <bits/stdc++.h>
using namespace std;

const int V = 9;

int minDistance(int dist[], bool done[]) {
	int min_index, min_dist = INT_MAX;

	//find next smallesr node which is not already done
	for(int i = 0; i < V; i++) {
		if(dist[i] < min_dist && !done[i]){
			min_dist = dist[i];
			min_index = i;
		}
	}

	return min_index;
}

void printSolution(int dist[]) 
{ 
    printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < V; i++) 
        printf("%d \t\t %d\n", i, dist[i]); 
}

void dijkstra(int graph[V][V], int src) {

	int dist[V];
	bool done[V];

	//initially all nodes will unvisited
	//and all nodes will have infinite distance
	for(int i = 0; i < V; i++) {
		dist[i] = INT_MAX;
		done[i] = false;
	}

	dist[src] = true;

	for(int i = 0; i < V; i++) {

		int start = minDistance(dist, done);
		//mark this node as done
		done[start] = true;

		for(int j = 0; j < V; j++) {
			//jth node should not be already visited
			//there should be a edge between start to j
			if(!done[j] && graph[start][j] && 
				dist[start] + graph[start][j] < dist[j]) {

				dist[j] = dist[start] + graph[start][j];
			}
		}
	}

	printSolution(dist);
}


int main() {

	/* Let us create the example graph discussed above */
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
  
    dijkstra(graph, 0); 
  
    return 0; 
}
