//https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        const int INF = 1e9 + 5;
        vector < vector <int> > dp(n, vector<int>(m));
        
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(row==0 && col==0){
                    dp[row][col] = grid[row][col];
                }
                else{
                    int prev = min((row==0?INF:dp[row-1][col]), (col==0?INF:dp[row][col-1]));
                    dp[row][col] = grid[row][col] + prev; 
                }
            }
        }
        return dp[n-1][m-1];
    }
};
