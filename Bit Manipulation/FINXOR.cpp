//https://www.codechef.com/SEPT20A/problems/FINXOR/


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


int main() {
    #ifndef ONLINE_JUDGE
      freopen("input1.txt","r",stdin);
      freopen("output1.txt","w",stdout);
    #endif
    int T; cin >> T;
    while(T--) {
      ll n; cin >> n;
      ll ans = 0, total = 0;
      cout << 1 << " " << (1 << 20) << endl;
      cin >> total;
      ans += (total&1);

      for(ll i = 1; i < 20; i++) {
        ll curr = (1 << 20) + (1 << i), x = 0;
        cout << 1 << " " << curr << endl;
        cin >> x;

        ll ones = ((abs(total - x) / (1 << i)) + n) / 2;
        if(total < x) ones = min(ones, n - ones);

        if(ones&1) ans += (1 << i);  
      }

      cout << 2 << " " << ans << endl;
      ll final; cin >> final;
      if(final == -1) break;
    }

    return 0;
}
