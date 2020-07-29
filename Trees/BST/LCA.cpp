//https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1

Node* LCA(Node *root, int p, int q)
{
   Node* ans = NULL;
   while(root) {
       int x = root -> data;
       if(x < p && x < q) {
           root = root -> right;
       }
       else if (x > p && x > q) {
           root = root -> left;
       }
       else {
           ans = root;
           break;
       }
   }
   return ans;
}
