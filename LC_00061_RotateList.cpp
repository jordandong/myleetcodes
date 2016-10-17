/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

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
    ListNode *rotateRight(ListNode *head, int k) {
        int l = 0;
        ListNode *fast = head;
        ListNode *slow = head;
        while(slow){
            l++;
            slow = slow->next;
        }
        if(l <= 1)
            return head;
        k = k % l;
        if(k == 0)
            return head;
        
        slow = head;
        fast = head;
        while(k-- > 0)
            fast = fast->next;
        
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        return head;
    }
};
