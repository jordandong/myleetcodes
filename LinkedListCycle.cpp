/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

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
    bool hasCycle(ListNode *head) {
        if(!head)
            return false; 
        
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(slow && fast){
            if(slow == fast)
                return true;
            if(!fast->next)
                return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};
