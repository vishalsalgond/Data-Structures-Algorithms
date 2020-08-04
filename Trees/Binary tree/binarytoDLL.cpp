//https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1


/* Structure for tree and linked list

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

// This function should return head to the DLL

void convert(Node *root, Node* &prev, Node* &head) {
    
    if(root == NULL) 
        return;
        
    convert(root -> left, prev, head);
    
    if(prev == NULL) {
        head = root;
    } else {
        root -> left = prev;
        prev -> right = root;
    }
    prev = root;
    
    convert(root -> right, prev, head);
    
}


Node * bToDLL(Node *root)
{
    Node *head = NULL, *prev = NULL;
    convert(root, prev, head);
    return head;
}
