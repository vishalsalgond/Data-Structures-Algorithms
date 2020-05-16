https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *last,*head;
        if(!l1) return  l2;
        if(!l2) return l1;
        if(l1->val<l2->val){
            head = l1;
            last = l1;
            l1 = l1->next;
        }  
        else{
            head = l2;
            last = l2;
            l2 = l2->next;
        }
        while(l1 && l2){
           if(l1->val<l2->val){
               last->next = l1;
               last = l1;
               l1 = l1->next;
           }
            else{
                last->next = l2;
                last = l2;
                l2 = l2->next;
            }
        }
        if(l2){
            last->next = l2;
        }
        if(l1){
            last->next = l1;
        }
        return head;
    }
};  

//Time complexity : O(n+m)
//Space complexity : O(1)



