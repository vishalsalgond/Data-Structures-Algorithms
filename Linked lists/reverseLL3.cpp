//https://leetcode.com/problems/reverse-linked-list-ii/

//The "first" pointer points to (m-1)th index. And if m=1 then first=NULL.
//We have to first decrement m by 1 before entering the loop to find (m-1)th node as we are not using a dummy node.
//Now the "last" pointer stores address of (m)th node(as it will be the last node once we reverse the list).
//Then we reverse the list from index m to n.
//Once we reverse the list "prev" pointer will contain address of nth index(head of the reversed list) and "temp" will contain address of (n+1)th node.
//Finally we connect "last" to (n+1)th node(temp) and "prev"(head of the reversed list) to "first".


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || !head->next) return head;
        ListNode *temp,*curr,*prev=NULL,*first,*last;
        temp = head;
        int loop = n-m+1;
        if(loop==0) return head;
        if(m==1) first = NULL;
        else{
            m--;
            while(--m>0){
                temp = temp->next;
            }
            first = temp;
            temp = temp->next;
            first->next = NULL;
        }
        //reverse the list from index m to n
        while(loop--){
            if(!prev) last = temp;
            curr = temp->next;
            temp->next = prev;
            prev = temp;
            temp = curr;
        }
        //connect prev to first and last to temp
        if(!first) head=prev;
        else first->next = prev;
        last->next = temp;
        return head;
    }
};
