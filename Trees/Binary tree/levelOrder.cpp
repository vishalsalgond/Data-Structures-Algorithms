//https://leetcode.com/problems/binary-tree-level-order-traversal/

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

#define min(a,b) a>b ? b : a;
class Solution {
    
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue <TreeNode*> Q;
        vector< vector <int> > levels;
        vector <int> curr;
        
        if(!root) return levels;
        
        Q.push(root);
        Q.push(NULL);
        
        //use NULL as a marker
        //NULL denotes that we have completed a level
        //after completing a level if there are stil
        //some nodes left in Queue add NULL again
        
        while(!Q.empty()){
            
            TreeNode* temp = Q.front();
            Q.pop();   
            
            if(!temp){
                levels.push_back(curr);
                curr.resize(0);
                if(Q.size()>0){
                    Q.push(NULL);
                }
            }
            else{
                curr.push_back(temp->val);
                if(temp->left) Q.push(temp->left);
                if(temp->right) Q.push(temp->right); 
            }
            
        }
        
        return levels;
    }
};
