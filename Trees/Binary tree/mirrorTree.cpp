//https://practice.geeksforgeeks.org/problems/mirror-tree/1
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
}; */

/* Should convert tree to its mirror */


void mirror(Node* node) 
{
    if(node == NULL) {
        return;
    }
    mirror(node->left);
    mirror(node->right);
    
    //swap left and right
    Node* temp = node->left;
    node->left = node->right;
    node->right = temp;
}
