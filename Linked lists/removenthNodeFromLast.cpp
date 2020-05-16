https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        int count=0;
        ListNode *temp=head;
        while(temp){
            temp = temp->next;
            count++;
        }
        if(n==count){
            head = head ->next;
            return head;
        }
        n = count-n-1;
        temp = head;
        while(n--) temp = temp->next;
        temp ->next = temp -> next -> next;
        return head;
    }
};
