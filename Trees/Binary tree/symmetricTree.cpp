//https://leetcode.com/problems/symmetric-tree/


//Recursive
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
    bool dfs(TreeNode *n1, TreeNode *n2){
        if(n1==NULL && n2==NULL) return true;
        
        else if(n1==NULL || n2==NULL) return false;
        
        else if(n1->val == n2->val){
            return dfs(n1->left, n2->right) && dfs(n1->right, n2->left);
        }
        
        else return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        
        if(root==NULL) return true;
        
        return dfs(root->left, root->right);
    }
};



//Iterative
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
    
public:
    bool isSymmetric(TreeNode* root) {
        
        if(root==NULL) return true;
        
        queue <TreeNode*> Q;
        Q.push(root);
        Q.push(root);
        
        while(!Q.empty()){
            TreeNode *leftNode = Q.front();
            Q.pop();
            TreeNode *rightNode = Q.front();
            Q.pop();
            
            if(!leftNode && !rightNode) continue;
            
            else if (!leftNode || !rightNode) return false;
            
            else if(leftNode->val != rightNode->val) return false;
            
            else{
                Q.push(leftNode->left);
                Q.push(rightNode->right);
                
                Q.push(leftNode->right);
                Q.push(rightNode->left);
            }
            
        }
        
        return true;
        
        
        
    }
};
