https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

struct node *reverse (struct node *head, int k)
{
    node *temp, *prev = NULL, *curr = head;
    int count = k;
    while(count-- && curr){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    if(head){
        head->next = reverse(temp,k);
    }
    return prev;
    
}
