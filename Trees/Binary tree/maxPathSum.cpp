//https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int ans;
    
    int dfs(TreeNode *root){
        if(root == NULL){
            return 0;
        }
        
        //get path sum of left and right subtree
        int x = dfs(root->left);
        int y = dfs(root->right);
        
        //upadte ans if left+right+root path is max
        ans = max(ans, x+y+root->val);
        
        //if max path is negative reuturn 0
        return max(0, root->val + max(x,y));
    }
public:
    
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        dfs(root);
        
        return ans;
        
    }
};
