//============================================================================
// Merge two sorted linked lists and return it as a new list. The new list
// should be made by splicing together the nodes of the first two lists.
//============================================================================


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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *head=new ListNode(-1);
        ListNode *curr=head;

        while(l1!=NULL&&l2!=NULL){
            if(l1->val<l2->val){
                curr->next = l1;
                l1=l1->next;
                curr=curr->next;
            }else{
                curr->next=l2;
                l2=l2->next;
                curr=curr->next;
            }   
        }
        if(l1!=NULL)
            curr->next=l1;
        else
            curr->next=l2;
        curr=head->next;
        delete head;
        return curr;
    }
};


class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = NULL;
        ListNode *node = NULL;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                if (head == NULL) {
                    head = l1;
                    node = head;
                }else {
                    node->next = l1;
                    node = node->next;
                }
                l1 = l1->next;
            }else{
                if (head == NULL) {
                    head = l2;
                    node = head;
                }else {
                    node->next = l2;
                    node = node->next;
                }
                l2 = l2->next;
            }
        }
        if (l1 == NULL) {
            if (head == NULL)
                head = l2;
            else
                node->next = l2;
        }
        else if (l2 == NULL) {
            if (head == NULL)
                head = l1;
            else
                node->next = l1;
        }
        return head;
    }
};
