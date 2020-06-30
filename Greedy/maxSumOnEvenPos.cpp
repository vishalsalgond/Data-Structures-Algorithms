//https://codeforces.com/contest/1373/problem/D


#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
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
#define max(a,b) ((a)>(b)?(a):(b))
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
//================================


int main() {
    ios_base::sync_with_stdio(0);
    int t, i, j, k, p, q, r, x, y, u, v, n, m;

    cin >> t;
    while(t--){
       cin >> n;
       vi a(n),odd,even;
       ll sum = 0;
       
       fo(i,n){
           cin >> a[i];
           if(i%2==0) sum += a[i];
       } 
       
       if(n==1){
           cout << sum << endl;
           continue;
       }
       
       if(n==2){
           cout << max(a[0],a[1]) << endl;
           continue;
       }
       
       for(int R=1;R<n;R=R+2){
           odd.push_back(a[R]-a[R-1]);
       }
       
       for(int R=2;R<n;R=R+2){
           even.push_back(a[R-1]-a[R]);
       }
       
       int nOdd = odd.size(), nEven = even.size();
       
       ll max_ending_here = odd[0], max_so_far = odd[0];
       for(int i=1; i<nOdd; i++){
           max_ending_here = max(max_ending_here+odd[i], odd[i]);
           max_so_far = max(max_so_far, max_ending_here);
       }
       
       ll final_max = max_so_far; 
       
       max_ending_here = even[0], max_so_far = even[0];
       for(int i=1; i<nEven; i++){
           max_ending_here = max(max_ending_here+even[i], even[i]);
           max_so_far = max(max_so_far, max_ending_here);
       }
       
       final_max = max(final_max, max_so_far);
       final_max = max(final_max, 0);
       
       cout << sum + final_max << endl;
    }

    return 0;
}

