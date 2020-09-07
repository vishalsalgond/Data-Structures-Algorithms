#include<bits/stdc++.h>
using namespace std;
#define loop0(i,n) for(i=0;i<n;i++)
#define loop1(i,n) for(i=1;i<n;i++)
#define loopr(i,n) for(i=n-1;i>=0;i--)
#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define nl "\n"
#define gcd __gcd
#define pb push_back
#define mp make_pair
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
ll fastpow(ll x,ll y)
{
  ll res = 1;x = x % mod;
  while (y > 0)
  { 
    if (y & 1)res = (res * x) % mod; 
    y = y >> 1 ; 
    x = (x * x) % mod; 
  } 
  return (res%mod);
}
//MODULAR INVERSE (based on fermat's little theorem, works when m is prime)
ll inv(ll x,ll m){ return fastpow(x , m - 2);}
//MODULAR DIVISION (given numbers need not to be co-prime)
ll moddiv(ll a,ll b)
{
  ll temp=gcd(a,b);
  a/=temp;
  b/=temp;
  return ((a*inv(b,mod))%mod);
}
//=========================  template ends here  ===========================

void foo() {
  
}
  

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
      freopen("input1.txt","r",stdin);
      freopen("output1.txt","w",stdout);
    #endif
    int T; cin >> T;
    for(int i = 1; i <= T; i++){
      foo();
    }
    return 0;
}

