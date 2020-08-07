https://practice.geeksforgeeks.org/problems/maximum-profit/0


//Time O(N*K)
//Space O(N*K)

#include <bits/stdc++.h>
using namespace std;

int foo(){
    int n,k;
    cin >> k >> n;
    vector<int>prices(n);
    for(int i = 0; i < n; i++)
        cin >> prices[i];
        
    if(n == 0 || k == 0)
        return 0;
    
    int dp[k+1][n];
    
    for(int i = 0; i < n; i++)
        dp[0][i] = 0;
    
    for(int i = 0; i < k + 1; i++)
        dp[i][0] = 0;
    
    for(int i = 1; i < k + 1; i++) {
        int maxDiff = -prices[0];
        for(int j = 1; j < n; j++) {
            int doNotBuy = dp[i][j - 1];
            int buyOnSomeDay = prices[j] + maxDiff;
            
            dp[i][j] = max(doNotBuy, buyOnSomeDay);
            
            maxDiff = max(maxDiff, dp[i - 1][j] - prices[j]);
        }
    }
                           
    return dp[k][n - 1];
}


int main() {
	int t;
	cin >> t;
	while(t--) {
	    cout << foo() << endl;;
	}
	return 0;
}
