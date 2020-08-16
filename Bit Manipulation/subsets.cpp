//https://leetcode.com/problems/subsets/


class Solution {
public:
    vector <vector<int>> ans;
    
    void filterNums(int n, vector <int> nums) {
        vector <int> temp;
        int j = 0;
        while(n > 0) {
            int last_bit = n & 1;
            if(last_bit) {
                temp.push_back(nums[j]);
            }
            j++;
            n = n >> 1;
        }
        ans.push_back(temp);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n = nums.size();
        
        for(int i = 0; i < (1 << n); i++) {
            filterNums(i, nums);
        }
        
        return ans;
    }
};
