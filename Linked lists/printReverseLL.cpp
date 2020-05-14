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
void reverseList(Node *head)
{
    if(!head){
        return;
    }
    reverseList(head->next);
    cout << head->data << " ";
    
}
