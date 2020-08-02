//https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1


* A binary tree node has data, pointer to left child
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
};
 */

// root: root node of the tree

void dfs(Node *root, map <int, vector<int> >& mp) {
    
    if(!root) return;
    
    queue< pair<Node*, int> > Q;
    int width = 0;
    Q.push({root, width});
    
    while(!Q.empty()) {
        
        pair<Node*, int> curr = Q.front();
        Q.pop();
        
        Node* node = curr.first;
        int width = curr.second;
        
        mp[width].push_back(node -> data);
        
        if(node -> left)
            Q.push({node -> left, width - 1});
            
        if(node -> right)
            Q.push({node -> right, width + 1});
    }
    
}

vector<int> verticalOrder(Node *root)
{
    map <int, vector<int> > mp;
    dfs(root, mp);
    
    vector <int> final;
    for(auto it : mp) {
        for(auto x : it.second) 
            final.push_back(x);
    }
    return final;
}

