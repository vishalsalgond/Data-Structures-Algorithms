//https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1


void topView(struct Node *root)
{
    if(!root) return;
    
    map <int, Node*> mp;
    deque <int> deq;
    queue < pair <int, Node*> > Q;
    
    Q.push({0, root});
    // deq.push_back(root -> data);
    
    while(!Q.empty()) {
       pair <int, Node*> curr = Q.front();
       Q.pop();
       
       if(mp[curr.first] == NULL) {
            if(curr.first > 0)
                deq.push_back(curr.second -> data);
            else
                deq.push_front(curr.second -> data);
           mp[curr.first] = curr.second;
       }
       
       if(curr.second -> left) 
            Q.push({curr.first - 1, curr.second -> left});
       
       if(curr.second -> right) 
            Q.push({curr.first + 1, curr.second -> right});
    }
    
    while(!deq.empty()) {
        cout << deq.front() << " ";
        deq.pop_front();
    }
}
