//https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A

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

ll getSum(ll BIT[], ll i){
    ll sum = 0;
    //due to 1-based indexing
    i += 1;
    
    while(i){
        sum += BIT[i];
        i -= i & (-i);
    }
    
    return sum;
}

void updateBIT(ll BIT[], ll n, ll i, ll val){
    //due to 1-based indexing
    i += 1;
    
    while(i <= n){
        BIT[i] += val;
        i += i & (-i);
    }
}

ll *constructBIT(vector<ll> arr, ll n){
    ll *BIT = new ll[n+1];
    ll i;
    for(ll i = 1; i <= n; i++){
        BIT[i] = 0;
    }
    
    for(ll i = 0; i < n; i++){
        updateBIT(BIT, n, i, arr[i]);
    }
    
    return BIT;
}

int main() {
    ios_base::sync_with_stdio(0);
    ll n,m,i;
    cin >> n >> m;
    
    vector<ll> arr(n);
    fo(i,n) cin >> arr[i];
    
    ll *BIT = constructBIT(arr, n);
    
    while(m--){
        int op;
        cin >> op;
        if(op == 1){
            ll i, v;
            cin >> i >> v;
            ll diff = v - arr[i];
            arr[i] = v;
            updateBIT(BIT, n, i, diff);
        } else{
            ll l,r;
            cin >> l >> r;
            cout << getSum(BIT, r-1) - getSum(BIT, l-1) << endl;
        }
    }
    
    return 0;
}

