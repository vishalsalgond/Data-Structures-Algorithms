/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */


void leftBoundary(vector <int> &ans, Node *temp) {
    while(temp) {
        if(temp -> right || temp -> left) 
            ans.push_back(temp -> data);
        if(temp -> left)
            temp = temp -> left;
        else
            temp = temp -> right;
    }
}

void inorder(vector <int> &ans, Node *root) {
    if(!root) 
        return;
    
    inorder(ans, root -> left);
    
    if(!(root -> left) && !(root -> right)) 
        ans.push_back(root -> data);
    
    inorder(ans, root -> right);
}

void rightBoundary(vector <int> &ans, Node *temp) {
    stack <int> s;
    while(temp) {
        if(temp -> right || temp -> left) 
            ans.push_back(temp -> data);
        if(temp -> right)
            temp = temp -> right;
        else
            temp = temp -> left;
    }
    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
}

vector <int> printBoundary(Node *root)
{
    vector <int> ans;
    if(!root) return ans;
        
    //push root to ans
    ans.push_back(root -> data);
    
    //start traversing left boundary
    if(root -> left) 
        leftBoundary(ans, root -> left);

    //traverse leaf nodes
    inorder(ans, root);
    
    //traverse right boundary
    if(root -> right) 
        rightBoundary(ans, root -> right);
    
    return ans;
}
