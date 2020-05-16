https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        unordered_map <int, int> lookup;
        ListNode *temp=head,*last;
        while(temp){
            lookup[temp->val]++;
            temp = temp -> next;
        }
        temp = head;
        head = NULL;
        while(temp){
            if(lookup[temp->val]==1){
                if(!head) head = temp;
                else last->next = temp;
                last = temp;
            }
            temp = temp->next;
        }
        if(last) last -> next = NULL;
        return head;
    }
};
