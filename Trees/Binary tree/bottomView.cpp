//https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1


/* Tree node class

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */

// Method that returns the bottom view.

vector <int> bottomView(Node *root)
{
   vector <int> ans;
   queue <pair<Node*, int>> Q;
   map <int, int > mp;
   Q.push({root, 0});
   
   while(!Q.empty()) {
       Node* curr = Q.front().first;
       int b = Q.front().second;
       
       Q.pop();
       
       mp[b] = curr -> data;
       
       if(curr -> left) 
           Q.push({curr -> left, b - 1});
       
       if(curr -> right) 
           Q.push({curr -> right, b + 1});
       
   }
   
   for(auto i : mp) 
       ans.push_back(mp[i.first]);
   
   return ans;
}

