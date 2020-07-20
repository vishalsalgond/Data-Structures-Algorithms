//https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0


//Time complexity O(n*k^2)
//Space O(n*k)

#include <bits/stdc++.h>
using namespace std;

int foo(){
    int n,k;
    cin >> n >> k;
    if(n == 1) return k;
    int dp[n+1][k+1];
    
    for(int i = 1; i <= n; i++) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    
    for(int i = 1; i <= k; i++) {
        dp[1][i] = i;
    }
    
    for(int i = 2; i <= n; i++) {
        for(int j = 2; j <= k; j++) {
            dp[i][j] = INT_MAX;
            for(int z = 1; z <= j; z++) {
                int res = 1 + max(dp[i-1][z-1], dp[i][j-z]);
                dp[i][j] = min(dp[i][j], res);
            }
        }
    }
    
    return dp[n][k];
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    cout << foo() << endl;
	}
 	return 0;
}
