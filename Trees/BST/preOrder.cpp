//https://practice.geeksforgeeks.org/problems/preorder-traversal/1

/* A binary tree node has data, pointer to left child
   and a pointer to right child  

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

//root --> left --> right

//recursive approach
void preorder(Node* root)
{
    if(!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


//iterative approach
void preorder(Node* root)
{
    stack <Node *> tree;
    tree.push(root);
    while(!tree.empty()){
        Node *temp = tree.top();
        tree.pop();
        if(temp){
            cout << temp->data << " ";
            tree.push(temp->right);
            tree.push(temp->left);   
        }
    }
}
