/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

/*  This function should rotate list counter-clockwise
    by k and return new head (if changed) */
Node* rotate(Node* head, int k) {
    if(!head || !head->next || k==0) return head;
    Node *temp=head,*new_head;
    int count=1;
    while(temp->next)
        temp = temp->next;
        count++;
    if(count==k) 
        return head;
    temp = head;
    for(int i=1;i<k;i++) 
        temp = temp->next;
    new_head = temp -> next;
    temp -> next = NULL;
    temp = new_head;
    while(temp->next) 
        temp = temp-> next;
    temp->next = head;
    return new_head;
    
}
