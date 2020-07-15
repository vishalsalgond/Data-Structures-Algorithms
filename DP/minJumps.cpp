//https://leetcode.com/problems/jump-game-ii/

//use optimal substructure property
//min jumps to reach i is
//min jumps to reach i - x plus
//min jums to reach x from i - x

//Time O(n*n)
//Space O(n)

class Solution {
public:
    int jump(vector<int>& nums) {
     
        int n = nums.size();
        int dp[n];
        
        dp[0] = 0;
        
        for(int i = 1; i < n; i++){
            dp[i] = INT_MAX;
        }
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] + j >= i){
                    dp[i] = min(dp[i], 1 + dp[j]);
                    break;
                }
            }
        }
        
        return dp[n-1];
    }
};


//TIme O(n)
//Space O(1)

class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();
        
        if(nums[0] == 0 || n == 1){
            return 0;
        }
        
        int can_reach = nums[0], steps = nums[0], jumps = 0;
        
        for(int i = 1; i < n-1; i++){
            can_reach = max(can_reach, i + nums[i]);
            steps -= 1;
            
            if(steps == 0){
                jumps += 1;
                steps = can_reach - i;
            }
        }
        
        return jumps + 1;
    }
};
