//https://leetcode.com/problems/path-sum-ii/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    vector <int> local;
    vector < vector <int> > total;
    
    void dfs(TreeNode *root, int sum){
        
        if(!root) return;
        
        local.push_back(root->val);
            
        if(!root->left && !root->right && root->val == sum){
            total.push_back(local);
        }
        
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);
        
        local.pop_back();
        
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        dfs(root, sum);
        
        return total;
    }
};
