//https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        int curr_max = nums[0]; //max positive product
        int curr_min = nums[0]; //min negative product
        int max_so_far = nums[0];
        
        for(int i = 1; i < n; i++) {
            
            int p1 = curr_max * nums[i];
            int p2 = curr_min * nums[i];
            
            curr_max = max(max(p1, p2), nums[i]);
            
            curr_min = min(min(p1, p2), nums[i]);
            
            if(curr_max > max_so_far) {
                max_so_far = curr_max; 
            }
        }
       
        return max_so_far;
    }
};
