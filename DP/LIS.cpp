//https://leetcode.com/problems/longest-increasing-subsequence/

//Time O(n*n)
//spcae O(n)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n);
        
        if(n==0) return 0;
        if(n==1) return 1;
        
        for(int i = 0; i < n; i++){
            //every elemment is a increasing sqn of length 1
            dp[i] = 1;
        }
        int max_val = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i] && dp[i] <= dp[j]){
                    dp[i] = 1 + dp[j];
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
