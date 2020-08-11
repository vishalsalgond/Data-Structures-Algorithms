//https://leetcode.com/problems/unique-binary-search-trees/


class Solution {
public:
    int numTrees(int n) {
        
        //catalan number
        //c(n) = c(0)*c(n-1) + c(1)*c(n-2) + c(2)*c(n-3) + ... + c(n-1)*c(0)
        
        int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++) {
            dp[i] = 0;
            for(int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};
