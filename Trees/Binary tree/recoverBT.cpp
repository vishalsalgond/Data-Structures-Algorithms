//https://leetcode.com/problems/recover-binary-search-tree/

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
    
    //Eg if inorder is 1 2 3 4 5
    //and we swap 2 & 4 then --> 1 4 3 2 5
    
    vector <TreeNode*> nodes;
    TreeNode *f=NULL,*s=NULL,*prev=NULL;
    
    void inorder(TreeNode* root)
    {
        if(!root) return;
        
        inorder(root->left);
        
        //first misplaced node
        if(f == NULL && prev != NULL && prev->val >= root->val){
            f = prev;
        }
        
        //second misplaced node
        if(f != NULL && prev->val >= root->val){
            s = root;
        }
        prev = root;
        
        inorder(root->right);
    }
    
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
       
        int temp = f->val;
        f->val = s->val;
        s->val = temp;
    }
};
