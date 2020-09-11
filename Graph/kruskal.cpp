#include<bits/stdc++.h>
using namespace std;
#define lp0(i,n) for(i=0;i<n;i++)
#define lp1(i,n) for(i=1;i<=n;i++)
#define lpr(i,n) for(i=n-1;i>=0;i--)
#define ll long long
#define nl "\n"
#define gcd __gcd
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pl;
typedef vector<int>   vi;
typedef vector<ll>    vl;
typedef vector<pii>   vpii;
typedef vector<pl>    vpl;
typedef vector<vi>    vvi;
typedef vector<vl>    vvl;
const ll mod = 1e9 + 7;
//LCM
inline ll lcm(ll a, ll b) { return ((a/gcd(a,b))*b); }
//MODULO OPEARTIONS
inline ll add(ll a, ll b) { return ((( (a%mod) + (b%mod)) % mod) + mod ) % mod ; }
inline ll sub(ll a, ll b) { return ((( (a%mod) - (b%mod)) % mod) + mod ) % mod ; }
inline ll mul(ll a, ll b) { return ((( (a%mod) * (b%mod)) % mod) + mod ) % mod ; }
//POWER
ll fastpow(ll x,ll y) {
  ll res = 1;x = x % mod;
  while (y > 0) { 
    if (y & 1) res = (res * x) % mod; 
    y = y >> 1 ; 
    x = (x * x) % mod; 
  } 
  return (res%mod);
}
//MODULAR INVERSE (based on fermat's little theorem, works when m is prime)
ll inv(ll x,ll m){ return fastpow(x , m - 2);}
//MODULAR DIVISION (given numbers need not to be co-prime)
ll moddiv(ll a,ll b) {
  ll temp=gcd(a,b);
  a/=temp;
  b/=temp;
  return ((a*inv(b,mod))%mod);
}
//=========================  template ends here  ===========================

class DSU {
  int *parent, *rank;
  int V;

public:
  DSU(int V) {
    this -> V = V;
    parent = new int[V];
    rank = new int[V];

    //initially all will node have parent as -1
    //and rank as 1
    int i;
    lp0(i,V) {
      parent[i] = -1;
      rank[i] = 1;
    } 
  }

  //Path compression optimization
  int DSU_find(int v) {
    if(parent[v] == - 1)
        return v;
    return parent[v] = DSU_find(parent[v]);
  }

  void DSU_union(int x, int y) {
    int s1 = DSU_find(x);
    int s2 = DSU_find(y);

    //Union by rank optimization
    if(s1 != s2) {
      if(rank[s1] > rank[s2]) {
        parent[s2] = s1;
        rank[s1] += rank[s2];
      } else {
        parent[s1] = s2;
        rank[s2] += rank[s1];
      }
    }
  }


};


class Graph {
  int V;
  vector < vector <int> > edgeList;
public:
  Graph(int V) {
    this -> V = V;
  }

  void addEdge(int u, int v, int w) {
    edgeList.push_back({w, u, v});
  }

  int kruskal() {
    //sort according to weights 
    //(will by default sort according to first character)
    sort(all(edgeList));

    DSU dsu(V);
    int ans = 0;
    //traverse all the nodes and include in MST if
    //they do not form cycle (parent of both are not same)
    for(auto edge : edgeList) {
      int w = edge[0];
      int u = edge[1];
      int v = edge[2];

      if(dsu.DSU_find(u) != dsu.DSU_find(v)) {
        dsu.DSU_union(u, v);
        ans += w;
      }
    }
    return ans;
  }
};
  

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
      freopen("input1.txt","r",stdin);
      freopen("output1.txt","w",stdout);
    #endif
    
    int V, e;

    Graph G(V);

    cin >> V >> e;
    while(e--) {
      int u, v, c;
      cin >> u >> v >> c;
      G.addEdge(u , v, c);
    }

    //call kruskal's function
    int ans = G.kruskal();
    cout << ans << nl;

    return 0;
}

