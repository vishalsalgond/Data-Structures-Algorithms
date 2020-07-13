//https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair/0

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int m = 1e9 + 7;

int main() {
    ll dp[100000];
    
    dp[0] = 1;
    dp[1] = 1;
    
    for(ll i = 2; i <= 100000; i++)
        dp[i] = (dp[i-1]%m + dp[i-2]%m)%m;
    
	int t; cin >> t;
	while(t--){
	    ll n; cin >> n;
	    cout << dp[n] << endl;
	}
	return 0;
}
