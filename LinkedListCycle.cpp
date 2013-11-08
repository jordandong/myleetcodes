/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
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
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!head)
            return false; 
        if(!head->next)
            return false;

        ListNode *slow = head;
        ListNode *fast = slow->next;
        while(slow&&fast){
            if(slow==fast)
                return true;
            if(!fast->next)
                return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};
