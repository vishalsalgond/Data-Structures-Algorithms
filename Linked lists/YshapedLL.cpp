https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1/

/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{
    int c1=1,c2=1;
    Node *temp = head1;
    while(temp->next){
        temp = temp->next;
        c1++;
    }
    temp = head2;
    while(temp->next){
        temp = temp->next;
        c2++;
    }
    Node *big=head1,*small=head2;
    if(c1>c2){ 
        for(int i=0;i<c1-c2;i++){
            big = big -> next;
        }
    }
    else{
        for(int i=0;i<c2-c1;i++){
            small = small -> next;
        }
        
    }
    while(big->next){
        if(big->next == small->next) 
            return big->next->data;
        big = big->next;
        small = small->next;
    }
    
    return -1;
}

