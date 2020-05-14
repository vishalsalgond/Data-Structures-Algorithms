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
// Should print the list in reverse order.
void reverseList(Node *head)
{
    if(!head){
        return;
    }
    reverseList(head->next);
    cout << head->data << " ";
    
}
