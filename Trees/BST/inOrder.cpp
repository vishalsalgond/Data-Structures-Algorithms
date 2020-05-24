//https://practice.geeksforgeeks.org/problems/inorder-traversal/1

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


// left --> root --> right

//recursive approach
void inorder(Node* root)
{
  if(!root) return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

//iterative approach
void inorder(Node* root)
{
  stack <Node *> tree;
  
  Node *curr = root;
  
  while(curr!=NULL || !tree.empty()){
      
      //push the left node till curr is not NULL
      while(curr){
          tree.push(curr);
          curr = curr -> left;
      }
      
      //if curr is NULL, print the parent node
      curr = tree.top();
      tree.pop();
      
      cout << curr -> data << " ";
      
      //move to the right subtree
      curr = curr -> right;
  }
}
