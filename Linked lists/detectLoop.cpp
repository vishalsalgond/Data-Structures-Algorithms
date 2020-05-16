https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

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
    bool hasCycle(ListNode *head) {
        ListNode *slow=head,*fast=head;
        while(slow && fast && fast->next){
            slow = slow ->next;
            fast = fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};
