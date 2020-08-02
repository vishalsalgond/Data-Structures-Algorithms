//Find smallest difference between two unsorted arrays


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


int foo() {
  int n, m, i;
  cin >> n >> m;
  vi a(n), b(m);
  fo(i,n) cin >> a[i];
  fo(i,m) cin >> b[i];

  sort(all(a));
  sort(all(b));

  int result = INT_MAX;
  int p1 = 0, p2 = 0;

  while(p1 < n && p2 < m) {

    if(abs(a[p1] - b[p2]) < result) 
      result = abs(a[p1] - b[p2]);

    if(a[p1] < b[p2]) 
      p1++;

    else 
      p2++;
  }

  return result;
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
      cout << foo() << endl;
      // cout << "Case #" << i <<" " << foo() << "\n";
    }
    return 0;
}

