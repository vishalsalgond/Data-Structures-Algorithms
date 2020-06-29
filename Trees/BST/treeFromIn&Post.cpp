//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    int postIndex; 
    
    unordered_map <int,int> lookup;
    
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int start, int end) {
        
        if(start > end){
            return NULL;
        }
        
        TreeNode *node = new TreeNode(postorder[postIndex--]);
        
        //if the node has no children
        if(start == end){
            return node;
        }
        
        int inIndex = lookup[node->val];
        
        //recursive calls
        node->right = build(inorder, postorder, inIndex+1, end);
        node ->left = build(inorder, postorder, start, inIndex-1);
        
        return node;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++){
            lookup[inorder[i]] = i;
        }
        postIndex = postorder.size()-1;
        return build(inorder, postorder, 0, postorder.size()-1);
    }
};
