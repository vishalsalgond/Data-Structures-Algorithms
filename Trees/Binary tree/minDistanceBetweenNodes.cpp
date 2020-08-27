//https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/* Should return minimum distance between a and b
   in a tree with given root*/
 
 Node *findLCA(Node *root, int a, int b) {
     
     if(!root) return NULL;
     
     Node *left = findLCA(root -> left, a, b);
     Node *right = findLCA(root -> right, a, b);
     
     if(root -> data == a || root -> data == b) 
        return root;
     
     if(left && right) return root;
     
     return left ? left : right;
 }   
 
 void dfs(Node *root, int depth, int &ans, int a, int b) {
     
     if(!root) return;
     
     if(root -> data == a || root -> data == b) 
        ans += depth;
     
     
     dfs(root -> left, depth + 1, ans, a, b);
     dfs(root -> right, depth + 1, ans, a, b);
 }
   
   
int findDist(Node* root, int a, int b) {
    Node *LCA = findLCA(root, a, b);
    int ans = 0;
    dfs(LCA, 0, ans, a, b);
    return ans;
}
