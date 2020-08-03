/*  the node structure is as follows

struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};
*/

// Should return the head of the copied linked list the
// output will be 1 if successfully copied


//Time O(N)
//Space O(N)
Node *copyList(Node *head) {
    
    map <Node*, Node*> mp;
    Node *temp = head;
    
    while(temp) {
        Node *newNode = new Node(temp -> data);
        mp[temp] = newNode;
        temp = temp -> next;
    }
    
    temp = head;
    while(temp) {
        mp[temp] -> next = mp[temp -> next];
        mp[temp] -> arb = mp[temp -> arb];
        temp = temp -> next;
    }
    
    return mp[head];
}


//Time O(N)
//Space O(1)

Node *copyList(Node *head) {
    
    Node *curr = head;
    
    //create the mapping
    while(curr) {
        Node *newNode = new Node(curr -> data);
        newNode -> next = curr -> next;
        curr -> next = newNode;
        curr = newNode -> next;
    }
    
    //fill the random pointers
    curr = head;
    while(curr) {
        if(curr -> arb == NULL)
            curr -> next -> arb = NULL;
        else
            curr -> next -> arb = curr -> arb -> next;
        curr = curr -> next -> next;
    }
    
    //restore the next pointers
    curr = head;
    Node *ans = curr -> next;
    while(curr -> next) {
        Node *temp = curr -> next;
        curr -> next = temp -> next;
        curr = temp;
    }
    
    return ans;
}
