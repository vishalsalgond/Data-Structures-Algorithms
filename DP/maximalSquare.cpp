//https://leetcode.com/problems/maximal-square/


class Solution {
public:
    int maximalSquare(vector<vector<char>>& M) {
        int n = M.size();
        if(n == 0) return 0;
        int m = M[0].size();
        
        int dp[n][m];
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dp[i][j] = (M[i][j] == '1' ? 1 : 0);
                if((i > 0 && j > 0) && dp[i][j] == 1) {
                    dp[i][j] += min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
                }
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans * ans;
    }
};
