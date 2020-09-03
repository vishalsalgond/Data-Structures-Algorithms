#include <bits/stdc++.h>
using namespace std;
 
map <char, vector < pair<char, int> >> mp;
map <char, int> h;
 
//template for node
class node {
public:
  char name;
  node *parent;
  int cost;
 
  node(char n, int c, node *p) {
    this -> name = n;
    this -> parent = p;
    this -> cost = c;
  }
};
 
//comparator for min_heap;
struct comp {
    bool operator ()(const node *a, const node *b) {
        return (a -> cost + h[a -> name]) > (b -> cost + h[b -> name]);
    }
};
 
 
void astar(char src, char des) {
 
  //min_heap
  priority_queue <node*, vector <node*>, comp> closedList, openList;
 
  node *curr = new node(src, 0, NULL);
  closedList.push(curr);
 
  while(closedList.top() -> name != des) {
    node *curr = closedList.top();
    closedList.pop();
 
    //explore all neigbouring nodes
    for(auto x : mp[curr -> name]) {
      char name = x.first;
      int cost = curr -> cost + x.second;
      node *parent = curr;
 
      node *newnode = new node(name, cost, parent);
      openList.push(newnode);
    }
 
    closedList.push(openList.top());
    openList.pop();
  }
  node *final = closedList.top();
  cout << "Optimal cost is " << final -> cost << endl;
 
  //backtrack to find the path
  vector <char> path;
  while(final -> parent) {
    path.push_back(final -> name);
    final = final -> parent;
  }
  path.push_back(final -> name);
 
 
  //print the path
  cout << "Path between " << src << " and " << des << " is: ";
  for(int i = (int)path.size() - 1; i > 0; i--) {
    cout << path[i] << " -> ";
  }
  cout << path[0] << endl;
 
}
 
 
int main() {
    #ifndef ONLINE_JUDGE
      freopen("input1.txt","r",stdin);
      freopen("output1.txt","w",stdout);
    #endif
    
    int V, e;
    cin >> V >> e;
 
    while(e--) {
      char u,v; int cost;
      cin >> u >> v >> cost;
      mp[u].push_back({v, cost});
    }
 
    for(int i = 0; i < V; i++) {
      char node; int hv;
      cin >> node >> hv;
      h[node] = hv;
    }
 
    char s ,d;
    cin >> s >> d;
 
    astar(s, d);
    return 0;
}
