//https://practice.geeksforgeeks.org/problems/delete-alternate-nodes/1


/*
Structure of the node of the binary tree
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    int data = x;
	    next = NULL;
	}
};
*/
// Complete this function
void deleteAlt(struct Node *head){
    Node *curr, *temp = head;
    while(temp && temp -> next){
        curr = temp -> next;
        temp -> next = temp -> next -> next;
        free(curr);
        temp = temp -> next;
    } 
}
