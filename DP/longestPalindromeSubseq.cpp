//https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        if(n == 1) return 1;
        int dp[n][n];
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) dp[i][j] = 1;
                else dp[i][j] = 0;
            }
        }
        
        int k = 1, i = 0, j = 1;
        
        while(i < n - k) {
            while(j < n) {
                if(s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i+1][j-1];
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
                }
                j++;
                i++;
            }
            j = k + 1;
            i = 0;
            k++;
        }
        
        return dp[0][n-1];
    }
};
