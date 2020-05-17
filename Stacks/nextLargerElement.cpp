//https://practice.geeksforgeeks.org/problems/next-larger-element/0#comment-4689344565

#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    stack<ll> stk;
	    vector<ll> a,ans(n,0);
	    for(int i=0;i<n;i++){
	        ll ele;
	        cin >> ele;
	        a.push_back(ele);
	    }
	    stk.push(0);
	    for(int i=1;i<n;i++){
	        if(a[i]>a[stk.top()]){
	            while(!stk.empty() && a[stk.top()]<a[i]){
	                ans[stk.top()] = a[i];
	                stk.pop();
	            }
	        }
	        stk.push(i);
	    }
	    while(!stk.empty()){
	        ans[stk.top()] = -1;
	        stk.pop();
	    }
	    
	    for(ll x:ans) cout << x << " ";
	    cout << endl;
	}
	return 0;
}
