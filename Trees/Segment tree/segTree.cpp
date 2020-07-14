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

struct segtree{
  int size;
  vl sums;
  
  void init(int n){
      size = 1;
      while(size < n) size *= 2;
      sums.assign(2*size, 0LL);
  }
  
  void setUtil(int i, int v, int x, int lx, int rx){
      // leaf node
      if(rx - lx == 1){
          sums[x] = v;
          return;
      }
      
      int mid = (lx + rx)/2;
      
      if(i < mid){
          setUtil(i, v, 2*x + 1, lx, mid);
      } else{
          setUtil(i, v, 2*x + 2, mid, rx);
      }
      
      //when returning from recursion
      sums[x] = sums[2*x + 1] + sums[2*x + 2];
      
  }
  
  void set(int i, int v){
      //start from root node
      setUtil(i, v, 0, 0, size);
  }
  
  ll getSumUtil(int l, int r, int x, int lx, int rx){
      //no overalp
      if(lx >= r || rx <= l) return 0;
      
      //complete overalp
      if(lx >= l && rx <= r){
          return sums[x];
      }
      
      //partial overalp
      int m = (lx + rx)/2;
      ll s1 = getSumUtil(l, r, 2*x + 1, lx, m);
      ll s2 = getSumUtil(l, r, 2*x + 2, m, rx);
      
      return s1 + s2;
  }
  
  ll getSum(int l, int r){
      return getSumUtil(l, r, 0, 0, size);
  }
};

int main() {
    ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    
    segtree st;
    st.init(n);
    
    for(int i = 0; i < n; i++){
        int v;
        cin >> v;
        st.set(i,v);
    }
    
    while(m--){
        int op;
        cin >> op;
        if(op == 1){
            int i, v;
            cin >> i >> v;
            st.set(i ,v);
        } else{
            int l,r;
            cin >> l >> r;
            cout << st.getSum(l,r) << endl;
        }
    }
    
    return 0;
}

