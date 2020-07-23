//https://practice.geeksforgeeks.org/problems/distinct-occurrences/1/?track=amazon-dynamic-programming&batchId=192

int subsequenceCount(string S, string T)
{
    int n = T.length();
    int m = S.length();
    int p = 1e9 + 7;
    if(n > m){
        return 0;
    }
    int dp[n+1][m+1];
    
    for(int i = 0; i <= n; i++) {
       for(int j = 0; j <= m; j++) {
           if(i == 0) {
               dp[i][j] = 1;
           } 
           else if(j == 0) {
               dp[i][j] = 0;
           }
           else if(T[i - 1] == S[j - 1]) {
               dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1])%p;
           } 
           else {
               dp[i][j] = dp[i][j - 1];
           }
       }
    }

    return dp[n][m];

}
