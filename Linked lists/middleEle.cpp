/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */

/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
    Node* temp=head;
    int count = 0;
    while(temp->next!=NULL){
        temp = temp->next;
        count++;
    }
    int mid = ((count+1)/2)+1;
    temp = head;
    for(int i=1;i<mid;i++){
        temp = temp -> next;
    }
    return temp->data;
    
    // Your code here
}
