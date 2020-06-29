//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    int preIndex = 0; 
    
    unordered_map <int,int> lookup;
    
    TreeNode *build(vector<int>& preorder, vector<int>& inorder,int start ,int end){
        
        if(start > end || preIndex > preorder.size()-1){
            return NULL;
        }
        
        TreeNode *node = new TreeNode(preorder[preIndex++]);
        
        //if the node has no children
        if(start == end){
            return node;
        }
        
        int inIndex = lookup[node->val];
        
        //recursive calls
        node->left = build(preorder, inorder, start, inIndex-1);
        node ->right = build(preorder, inorder, inIndex+1, end);
        
        return node;
        
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i = 0; i < inorder.size(); i++){
            lookup[inorder[i]] = i;
        }
        
        return build(preorder, inorder, 0, preorder.size()-1);
        
    }
};
