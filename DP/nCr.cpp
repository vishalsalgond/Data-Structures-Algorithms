//https://practice.geeksforgeeks.org/problems/ncr-1587115620/1/?track=amazon-dynamic-programming&batchId=192

//Expected Time Complexity : O(N*R)
//Expected Auxiliary Space: O(N)

// Returns nCr % p 
int nCrModp(int n, int r) 
{ 
    //nCr = (n-1)C(r-1) + (n-1)Cr
    int dp[n+1][r+1];
    if(n < r) return 0;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= min(i,r); j++) {
            if(j == 0 || j == i) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%p;
            }
        }
    }
    return dp[n][r];
} 
