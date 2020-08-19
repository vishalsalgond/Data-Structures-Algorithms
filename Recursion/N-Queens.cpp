//https://leetcode.com/problems/n-queens/


class Solution {
public:
    vector < vector <string> > ans;
    
    void backtrack(vector <string> &grid, vector<bool> &mp_col, vector<bool> &mp_45, vector<bool> &mp_135, int row) {
        
        int n = grid.size();
        if(row == n) {
            ans.push_back(grid);
            return;
        }
        
        for(int col = 0; col < n; col++) {
            if(!mp_col[col] && !mp_45[row + col] && !mp_135[n - 1 + col - row]) {
                
                grid[row][col] = 'Q';
                mp_col[col] = mp_45[row + col] = mp_135[n - 1 + col - row] = true;
                
                backtrack(grid, mp_col, mp_45, mp_135, row + 1);
                
                mp_col[col] = mp_45[row + col] = mp_135[n - 1 + col - row] = false;
                grid[row][col] = '.';
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector <string> grid(n, string(n, '.'));
        vector<bool> mp_col(n, false), mp_45(2*n, false), mp_135(2*n, false);
        backtrack(grid, mp_col, mp_45, mp_135, 0);
        
        return ans;
    }
};
