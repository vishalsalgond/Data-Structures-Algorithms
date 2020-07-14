//https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n,w;
	    cin >> n >> w;
	    vector<int> val(n),wt(n);
	    for(int i = 0; i < n; i++) cin >> val[i];
	    for(int i = 0; i < n; i++) cin >> wt[i];
	    
	    int dp[n+1][w+1];
	    
	    for(int i = 0; i <= n; i++){
	        for(int j = 0; j <= w; j++){
	            if(i==0 || j==0){
	                dp[i][j] = 0;
	                continue;
	            }
	            if(wt[i-1] > j){
	                dp[i][j] = dp[i-1][j];
	            } else {
	                dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][j - wt[i-1]]);
	            }
	        }
	    }
	   
	    cout << dp[n][w] << endl;
	}
	return 0;
}
