//https://practice.geeksforgeeks.org/problems/check-if-subtree/1


/* A binary tree node

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

/*you are required to
complete this function */

bool identical(Node *root1, Node *root2) {
    
    if(!root1 && !root2)
        return true;
        
    else if(!root1 || !root2)
        return false;
        
    else if(root1 -> data == root2 -> data) {
        bool left = identical(root1 -> left, root2 -> left);
        bool right = identical(root1 -> right, root2 -> right);
        
        return left && right;
    }
    
    else 
        return false;
}

bool isSubTree(Node* T, Node* S) {
    
    if(T == NULL) 
        return false;
        
    if(S == NULL)
        return true;
        
    if(identical(T, S))
        return true;
        
    bool checkRight = isSubTree(T -> right, S);
    bool checkLeft = isSubTree(T -> left, S);
    
    return checkRight || checkLeft;
}
