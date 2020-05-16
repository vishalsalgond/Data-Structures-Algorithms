https://leetcode.com/problems/linked-list-cycle-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       ListNode *slow=head,*fast=head,*loop_node=NULL;
        while(slow && fast && fast->next){
            slow = slow ->next;
            fast = fast->next->next;
            if(slow==fast){
                loop_node = slow;
                break;
            }
        }
        int index=0;
        if(loop_node==NULL) return NULL;
        slow = head;
        while(1){
            fast = loop_node;
            while(fast->next!=loop_node && fast->next!=slow){
                fast = fast -> next;
            }
            if(fast->next==slow) break;
            slow = slow -> next;
            index++;
        }
        fast->next = NULL;

        return head; 
    }
};
