//Path compression optimization
//Union by rank optimisation


#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pl;
typedef vector<int>   vi;
typedef vector<ll>    vl;
typedef vector<pii>   vpii;
typedef vector<pl>    vpl;
typedef vector<vi>    vvi;
typedef vector<vl>    vvl;
//========================================

class Graph {

  int V;
  list < pair <int,int> > adj;

public:
  Graph (int V) {
    this -> V = V;
  }

  void addEdge(int u, int v) {
    adj.push_back({u, v});
  }

  int find_set(int v, int parent[]) {
    if(parent[v] == -1)
      return v;

    return parent[v] = find_set(parent[v], parent);
  }


  void do_union(int a, int b, int parent[], int rank[]) {

    int s1 = find_set(a, parent);
    int s2 = find_set(b, parent);

    if(s1 != s2) {
      if(rank[s1] < rank[s2]) {
        parent[s1] = s2;
        rank[s2] += rank[s1];
      } else {
        parent[s2] = s1;
        rank[s1] += rank[s2];
      }
    }
  }

  bool contains_cycle() {
    int *parent = new int[V + 1];
    int *rank = new int[V + 1];

    for(int i = 0; i < V; i++) {
      parent[i] = -1;
      rank[i] = 1;
    }

    for(auto edge : adj) {
      int u = edge.first;
      int v = edge.second;

      int s1 = find_set(u, parent);
      int s2 = find_set(v, parent);


      if(s1 != s2){
        do_union(u, v, parent, rank);
      }
      else {
        return true;
      }
    }

    delete [] parent;
    delete [] rank;

    return false;
  }

};


int main() {
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
      freopen("input1.txt","r",stdin);
      freopen("output1.txt","w",stdout);
    #endif
    int v, e;
    cin >> v >> e;

    Graph g(v);

    while(e--) {
      int x, y;
      cin >> x >> y;
      g.addEdge(x, y);
    }

    cout << g.contains_cycle() << endl;
 
    return 0;
}

