//https://leetcode.com/problems/diagonal-traverse/


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        
        vector <int> ans;
        int n = matrix.size();
        if(n == 0) return ans;
        int m = matrix[0].size();
        
        vector <vector <int>> diagonals(n + m - 1);
        
        for(int i = 0; i < n + m - 1; i++) {
            int row = min(i, n - 1);
            int col = max(0, i - n + 1);
            
            for(; row >= 0 && col < m; row--, col++) {
                diagonals[i].push_back(matrix[row][col]);
            }
        }
        
        for(int i = 0; i < n + m - 1; i++) {
            if(i&1) {
                ans.insert(ans.end(), diagonals[i].rbegin(), diagonals[i].rend());
            }  else {
                ans.insert(ans.end(), diagonals[i].begin(), diagonals[i].end());
            }
        }
        
        return ans;
    }
};
