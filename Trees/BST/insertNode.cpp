//https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1

/* The structure of a BST node is as follows:

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

*/

// The function returns the root of the BST (currently rooted at 'root') 
// after inserting a new Node with value 'Key' into it. 

//iterative approach
Node* insert(Node* root, int key)
{
    if(root == NULL){
        Node *root = new Node(key);
        return root;
    }
    Node *curr = root;
    while(curr){
        if(key > curr->data){
            if(curr -> right == NULL){
                curr -> right = new Node(key);
                return root;
            }
            curr = curr -> right;
        } 
        else if(key < curr->data){
            if(curr -> left == NULL){
                curr -> left = new Node(key);
                return root;
            }
            curr = curr -> left;
        }
        else break;
    }
    return root;
}


//recursive approach
Node* insert(Node* root, int key)
{
    if(!root){
        return new Node(key);
    }
    else if(root->data < key){
        root->right = insert(root->right, key);
    }
    else if(root->data > key){
        root->left = insert(root->left, key);
    }
    return root;
}
