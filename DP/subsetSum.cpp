//https://practice.geeksforgeeks.org/problems/subset-sum-problem2643/1/?track=amazon-dynamic-programming&batchId=192

bool findPartition(int a[], int n) {
    int total = 0;
    for(int i = 0; i < n; i++) 
        total += a[i];
    
    if(total&1) return false;
    int need = total / 2;
    
    bool dp[n+1][need+1];
    for(int i = 0; i <= n; i++) {
        dp[i][0] = true;
        if(a[i - 1] > need) {
            return false;
        }
    }
    
    for(int i = 1; i <= need; i++)
        dp[0][i] = false;
        
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= need; j++) {
            if(j < a[i-1]){
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j] || dp[i-1][j - a[i - 1]];
            }
        }
    }
    return dp[n][need];
}
