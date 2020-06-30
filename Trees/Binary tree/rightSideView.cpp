//https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> rightSideView(TreeNode* root) {
        
        queue <TreeNode*> Q;
        vector< int > right;
        int curr;
        
        if(!root) return right;
        
        Q.push(root);
        Q.push(NULL);
        
        //we use null as marker for completion of level
        //in every level the node before null
        //will be the rightmost node in that level
        
        while(!Q.empty()){
            
            TreeNode* temp = Q.front();
            Q.pop();   
            
            if(!temp){
                right.push_back(curr);
                if(Q.size()>0){
                    Q.push(NULL);
                }
            }
            else{
                curr = temp->val;
                if(temp->left) Q.push(temp->left);
                if(temp->right) Q.push(temp->right); 
            }
            
        }
        
        return right;

    }
};
