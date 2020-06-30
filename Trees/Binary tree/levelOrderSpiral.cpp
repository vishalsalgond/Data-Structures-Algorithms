//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue <TreeNode*> Q;
        vector< vector <int> > levels;
        vector <int> curr;
        
        if(!root) return levels;
        bool level = true;
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
                if(level) levels.push_back(curr);
                else{
                    reverse(curr.begin(),curr.end());
                    levels.push_back(curr);
                }
                curr.resize(0);
                if(Q.size()>0){
                    Q.push(NULL);
                    level = !level;
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
