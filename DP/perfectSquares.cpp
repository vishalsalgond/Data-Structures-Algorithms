//https://leetcode.com/problems/perfect-squares/

//Time O(n*sqrt(n))
//Space O(n)

class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        if(n < 4) return n;
        for(int i = 0; i < 4; i++) {
            dp[i] = i;
        }
        
        for(int i = 4; i <= n; i++) {
            dp[i] = i; //max steps will be i
            for(int j = 1; j*j <= i; j++) {
                //keep breaking into squares
                dp[i] = min(dp[i], 1 + dp[i-j*j]);
            }
        }
        
        return dp[n];
    }
};
