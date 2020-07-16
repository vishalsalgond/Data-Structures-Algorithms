https://leetcode.com/problems/move-zeroes/


//Time O(n)
//Space O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n==0 || n == 1)
            return;
        int left = 0, right = 0;
        while(right < n){
            if(nums[right] == 0){
                right++;
            } else {
                swap(nums, left, right);
                left++;
                right++;
            }
            
        }
    }
    
    void swap(vector<int> &nums, int j, int i){
        int temp;
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    
};
