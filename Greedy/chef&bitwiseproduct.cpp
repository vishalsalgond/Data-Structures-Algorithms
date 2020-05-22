//https://www.codechef.com/problems/CHANDF

#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define ull unsigned long long
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
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
const int mod = 1000000007;
#define M 40
//=================================
ll binary_helper(bitset<M>A){
    ll temp=0;
    for(int i=0;i<40;i++){
        if(A[i]==1){
            temp+=pow(2,i);
        }
    }
    return temp;
}


ll F(bitset<M>X,bitset<M>Y,bitset<M>Z){
    bitset<M> first=X&Z,second=Y&Z;
    ll temp = first.to_ullong()*second.to_ullong();
    return temp;
}

int main() {
    ios_base::sync_with_stdio(0);
    ll x,y,l,r,t;
    cin >> t;
    while(t--){
        cin >> x >> y >> l >> r;
        if(min(x,y)==0){
            if(l==0){
                cout << 0 << endl;
            }
            else{
                cout << l << endl;
            }
            continue;
        }
        ll o;
        o = x|y;
        if(o>=l && o<=r){
            cout << o << endl;
            continue;
        }
        if(r==0){
            cout << 0 << endl;
            continue;
        }
        
        if(l==r){
            cout << l << endl;
            continue;
        }
        
        bitset<M> X(x),Y(y),L(l),R(r),ans;

        //find the position where the bits differ for the first time
        int k = 39;
        while(L[k]==R[k]) k--;
        
        ll curr_max=0;
        
        //Group 1(z1)
        //for all z1 kth bit will be 0
        for(int l1=k-1;l1>=0;--l1){
            bitset<M>z1=L;
            if(L[l1]==0){
                z1.set(l1,1);
                
                for(int i=l1-1;i>=0;i--){
                    if(X[i]==0 && Y[i]==0) z1.set(i,0);
                    else z1.set(i,1);
                }
                if(F(X,Y,z1)>=curr_max){
                    curr_max = F(X,Y,z1);
                    ans = z1;
                }
            }
        }

        //Group 2(z2)
        //for all z2 kth bit will be 1
        for(int l1=k-1;l1>=0;--l1){ 
            bitset<M>z2=R;
            if(R[l1]==1){
                z2.set(l1,0);
                for(int i=l1-1;i>=0;i--){
                    if(X[i]==0 && Y[i]==0) z2.set(i,0);
                    else z2.set(i,1);
                }
                if(F(X,Y,z2)>curr_max){
                    curr_max = F(X,Y,z2);
                    ans = z2;
                }
            }
        }
        
        //check for Z=L and Z=R
        if(F(X,Y,L)>=curr_max){
            curr_max = F(X,Y,L);
            ans = L;
        }
        if(F(X,Y,R)>curr_max){
            curr_max = F(X,Y,R);
            ans =  R;
        }

        ll f_ans=binary_helper(ans);
        
        cout << f_ans << endl;
    }

    return 0;
}

