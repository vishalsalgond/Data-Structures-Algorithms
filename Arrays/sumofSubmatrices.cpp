//https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/


class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        
        
        //build prefix matrix
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i > 0) 
                    matrix[i][j] += matrix[i - 1][j];
                
                if(j > 0) 
                    matrix[i][j] += matrix[i][j - 1];
                
                if(i > 0 && j > 0)
                    matrix[i][j] -= matrix[i - 1][j - 1];
                
            }
        }

        //find sum of submatrices
        for(int tr = 0; tr < n; tr++) {
            for(int tc = 0; tc < m; tc++) {
                for(int br = tr; br < n; br++) {
                    for(int bc = tc; bc < m; bc++) {
                        
                        int sum = matrix[br][bc];
                        
                        if(tc > 0) sum -= matrix[br][tc - 1];
                        if(tr > 0) sum -= matrix[tr - 1][bc];
                        if(tc > 0 && tr > 0) sum += matrix[tr - 1][tc - 1];

                        if(sum == target) ans++;
                    }
                }
            }
        }
        return ans;
    }
};
