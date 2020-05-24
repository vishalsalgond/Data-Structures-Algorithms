//https://practice.geeksforgeeks.org/problems/postorder-traversal/1/

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

//left --> right --> root

//recursive approach
void postOrder(Node* root)
{
  if(!root) return;
  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}

//iterative approach
void postOrder(Node* root)
{
  stack <Node *> s1, s2;
  
  s1.push(root);
  
  while(!s1.empty()){
      Node *temp = s1.top();
      s1.pop();
      //push top of s1 to s2
      s2.push(temp);
      
      //push left and right nodes of top to s1
      if(temp->left) s1.push(temp->left);
      if(temp->right)  s1.push(temp->right);
  }
  
  //s2 stores elements in the order
  // root , right , left
  //so we have to print s2 in reverse order
  while(!s2.empty()){
      cout << s2.top()->data << " ";
      s2.pop();
  }
}
