https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
// Should reverse list and return new head.

//iterative solution
Node* reverseList(Node *head)
{
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *temp, *prev = NULL, *curr = head;
    while(curr->next!=NULL){
       temp = curr;
       curr = curr -> next;
       temp -> next = prev;
       prev = temp;
    }
    curr -> next = prev;
    head = curr;
    return head;
}

//recursive solution
Node* reverseList(Node *head)
{
    if(!head || !head->next){
        return head;
    }
    Node *node = reverseList(head->next);
    head -> next -> next = head;
    head -> next = NULL;
    return node;
}
