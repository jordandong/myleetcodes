/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

Hide Tags Linked List Two Pointers
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
    ListNode *partition(ListNode *head, int x) {
        ListNode* first_head = NULL;
        ListNode* first_tail = NULL;
        ListNode* second_head = NULL;
        ListNode* second_tail = NULL;
        while(head){
            if(head->val < x){
                if(!first_head){
                    first_head = head;
                    first_tail = head;
                }else{
                    first_tail->next = head;
                    first_tail = first_tail->next;
                }
            }else{
                if(!second_head){
                    second_head = head;
                    second_tail = head;
                }else{
                    second_tail->next = head;
                    second_tail = second_tail->next;
                }
            }
            head = head->next;
        }

        if(first_tail)
            first_tail->next = second_head;
        else
            return second_head;
        
        if(second_tail)
            second_tail->next = NULL;

        return first_head;
    }
};
