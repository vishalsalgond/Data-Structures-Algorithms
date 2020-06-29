//https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
    
    int dfs(TreeNode *root){
        
        if(!root) return 0;
        
        int L = dfs(root->left);
        int R = dfs(root->right);
        
        //ask child node to give min depth
        //if one of them is 0 then return the other one
        return 1 + (min(L, R) ? min(L, R) : max(L, R));;
    }
public:
    int minDepth(TreeNode* root) {
        
        if(!root) return 0;
        
        return dfs(root);
    }
};
