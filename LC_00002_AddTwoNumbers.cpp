/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

Hide Tags Linked List Math
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = NULL;
        ListNode *cur = NULL;
        int carry = 0;
        while(l1 || l2){
            ListNode *t = NULL;
            if(l1 && l2){
                t = new ListNode((l1->val + l2->val + carry)%10);
                carry = (l1->val + l2->val + carry)/10;
                l1 = l1->next;
                l2 = l2->next;
            }else if(l1){
                t = new ListNode((l1->val + carry)%10);
                carry = (l1->val + carry)/10;
                l1 = l1->next;
            }else if(l2){
                t = new ListNode((l2->val + carry)%10);
                carry = (l2->val + carry)/10;
                l2 = l2->next;
            }
            
            if(!head){
                head = t;
                cur = head;
            }else{
                cur->next = t;
                cur = cur->next;
            }
        }
        if(carry){
            cur->next = new ListNode(carry);
        }
        return head;
    }
};
