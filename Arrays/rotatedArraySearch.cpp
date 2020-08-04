//https://leetcode.com/problems/search-in-rotated-sorted-array/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while(left <= right) {
            
            int mid = (left + right) / 2;
            
            if(nums[mid] == target)
                return mid;
            
            //when left half is sorted
            if(nums[left] <= nums[mid]) {
                //lies in left half
                if(target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            
            }
            //when right half is sorted
            else {
                //lies in right half
                if(target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            
        }
        
        return -1;
    }
};
