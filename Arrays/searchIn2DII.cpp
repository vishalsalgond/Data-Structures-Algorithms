//https://leetcode.com/problems/search-a-2d-matrix-ii/submissions/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        
        int row = -1;
        int n = a.size();
        if(n == 0) return false;
        
        int m = a[0].size();
        if(m == 0) return false;
        
        int i = n - 1, j = 0;
        
        while(i >= 0 && j < m) {
            
            if(a[i][j] == target) {
                return true;
            }
            else if(a[i][j] > target) {
                i--;
            } else {
                j++;
            }
        }
        
        return false;
    }
};
