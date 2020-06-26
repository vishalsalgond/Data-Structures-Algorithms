//https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int,int> lookup;
        int n = nums.size();
        int total = 0, ans = 0;
        lookup[total]++;
        
        for(int r=0; r<n; r++){
            total += nums[r];
            
            int need = total - k;
            ans += lookup[need];
            lookup [total]++;
                
        }
        
        return ans;
        
    }
};
