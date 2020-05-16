//https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1
//https://leetcode.com/problems/rotate-list/

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


/*  This function should rotate list clockwise
    by k and return new head (if changed) */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        ListNode *temp=head,*new_head;
        int count=0;
        while(temp){
            temp = temp->next;
            count++;
        }
        if(k%count==0) return head;
        k = k%count;
        temp = head;
        for(int i=1;i<count-k;i++){
            temp = temp->next;
        }
        new_head = temp -> next;
        temp -> next = NULL;
        temp = new_head;
        while(temp->next) temp = temp-> next;
        temp->next = head;
        return new_head;
    }
};
