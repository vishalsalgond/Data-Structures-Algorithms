class Solution {
public:
    vector < vector<int>> ans;
    vector <int> vec;
    
    void backtrack(vector<int> candidates, int target, int curr_sum, vector <int> curr_vec, int start) {
        
        // for(int x : curr_vec) 
        //     cout << x << " ";
        // cout << endl;
        
        if(curr_sum >= target) {
            if(curr_sum == target) 
                ans.push_back(curr_vec);
            return;
        }
        
        for(int i = start; i < candidates.size(); i++) {
            //do this only when required sum is greates than candidates[i]
            if(target - curr_sum >= candidates[i]) {
                curr_sum += candidates[i];
                curr_vec.push_back(candidates[i]);

                backtrack(candidates, target, curr_sum, curr_vec, i);

                curr_vec.pop_back();
                curr_sum -= candidates[i];
            }
        }
    }
        
        
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vec = {};
        backtrack(candidates, target, 0, vec, 0);
        
        return ans;
    }
};
