//https://leetcode.com/problems/remove-duplicates-from-sorted-array/

//Time O(n)
//space O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0) {
            return 0;
        }
        
        int i = 0;
        for(int j = 1; j < n; j++) {
            //condition means dupicate run has ended
            if(nums[i] != nums[j]) {
                i++;
                //increment the pointer and move
                //this new unique element to i
                nums[i] = nums[j];
            }
        }
        //return sorted subarray without duplicates
        return i + 1;
    }
};
