/*
Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?

Hide Tags Linked List
*/

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
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = NULL;
        while(head){
            ListNode *tmp = head->next; 
            head->next = new_head;
            new_head = head;
            head = tmp;
        }
        return new_head;
    }
};

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
    ListNode* reverseList(ListNode* head) {
        ListNode *new_head = NULL;
        reverseListHelper(head, new_head);
        return new_head;
    }
    
    ListNode* reverseListHelper(ListNode* head, ListNode* &new_head) {
        if(!head)
            return head;
        ListNode *tail = reverseListHelper(head->next, new_head);
        if(tail){
            tail->next = head;
            head->next = NULL;
        }else{
             new_head = head;
        }
        return head;
    }
};
