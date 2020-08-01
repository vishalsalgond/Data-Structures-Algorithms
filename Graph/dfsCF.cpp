//https://codeforces.com/contest/1388/problem/C

#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define nl "\n"
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
#define clr(x,z) memset(x, z, sizeof(x))
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
const ll N = 100005;
bool possible = true;
vector <ll> adj[N], p(N), h(N), total(N), good(N);
bool visited[N];

void dfs(ll v) {
  visited[v] = true;
  total[v] = p[v];
  ll total_good = 0;

  for(auto m : adj[v]){
    if(!visited[m]) {
      dfs(m);
      total_good += good[m];
      total[v] += total[m];
    }
  }
  good[v] = (h[v] + total[v]) / 2;

  if((h[v] + total[v])&1) {
    possible = false;
  }
  if(good[v] < 0 || good[v] > total[v]) {
    possible = false;
  }
  if(total_good > good[v]) {
    possible = false;
  }
}

void foo() {
  ll n,m;
  cin >> n >> m;

  for(int i = 1; i <= n; i++) cin >> p[i];
  for(int i = 1; i <= n; i++) cin >> h[i];
  for(int i = 1; i <= n; ++i) adj[i].clear();
  
  for(int i = 1; i < n; i++){
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for(int i = 1; i <= n; i++) visited[i] = false;
  
  dfs(1);
  if(possible) cout << "YES" << nl;
  else cout << "NO" << nl;
  possible = true;
}
  

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
      freopen("input1.txt","r",stdin);
      freopen("output1.txt","w",stdout);
    #endif
    int T; cin >> T;
    for(int i = 1; i <= T; i++){
      foo();
      // cout << "Case #" << i <<" " << foo() << "\n";
    }
    return 0;
}

