//https://leetcode.com/problems/edit-distance/

class Solution {
public:
    int minDistance(string input, string output) {
        int m = input.length();
        int n = output.length();
        
        int dp[m+1][n+1];
        
        for(int i = 0; i <= m; i++) 
            dp[i][0] = i;
        
        for(int i = 0; i <= n; i++)
            dp[0][i] = i;
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(input[i-1] == output[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    int min_ir = min(dp[i-1][j] + 1, dp[i][j-1] + 1);
                    dp[i][j] = min(min_ir, dp[i-1][j-1] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
