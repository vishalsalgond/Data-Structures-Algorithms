//Time Complexity : O(V + E)
//Space Complecity : O(V)


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


void dfs(vector <int> adj[], vector <int> &vis, int curr, stack <int> &s) {
  vis[curr] = true;

  for(int x : adj[curr]) {
    if(!vis[x])
      dfs(adj, vis, x, s);
  }

  s.push(curr);
}

void dfs_r(vector <int> adjr[], vector <int> &vis, int curr) {
  vis[curr] = true;

  for(int x : adjr[curr]) {
    if(!vis[x])
      dfs_r(adjr, vis, x);
  }
  cout << curr << " ";
}

int main() {
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
      freopen("input1.txt","r",stdin);
      freopen("output1.txt","w",stdout);
    #endif
    int T; cin >> T;
    for(int i = 1; i <= T; i++){
      int n, e;
      cin >> n >> e;
      vector <int> adj[n], adjr[n];

      //build normal and reverse graph
      while(e--) {
        int x , y;
        cin >> x >> y;
        adj[x].push_back(y);
        adjr[y].push_back(x);
      }

      //dfs on normal graph
      //store the vertices in a stack
      stack <int> s;
      vector <int> vis(n, 0);
      for(int i = 0; i < n; i++) {
        if(!vis[i])
          dfs(adj, vis, i, s);
      }

      //dfs on reverse graph
      vis.clear();
      vis.assign(n, 0);
      int color = 0;
      while(!s.empty()) {
        int x = s.top();
        s.pop();
        if(!vis[x]) {
          color++;
          dfs_r(adjr, vis, x);
          cout << endl;
        }
      }
      cout << "No of strongly connected components : ";
      cout << color  << endl;
    }
    return 0;
}

