//https://leetcode.com/problems/search-a-2d-matrix/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int n = a.size();
        
        if(n == 0) return false;
        int m = a[0].size();
        
        if(m == 0) return false;
        int found = -1;
        
        //find the row which contains that element
        int low = 0, high = n - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
           
            //when we found the array which might contain the target
            if(target >= a[mid][0] && target <= a[mid][m - 1]) {
                found = mid;
                break;
            }
            else if(target > a[mid][0]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        if(found == -1) return false;
        
        low = 0, high = m - 1;
        
        //search for that element in that row
        while(low <= high) {
            int mid = (low + high) / 2;
            
            if(target == a[found][mid]) {
                return true;
            }
            else if(target < a[found][mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        return false;
    }
};
