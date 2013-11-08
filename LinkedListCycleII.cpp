/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

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
    ListNode *detectCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!head || !head->next)
            return NULL;
            
        ListNode *slow = head;
        ListNode *fast = slow;
        while(true){
            if(!slow || !fast || !fast->next)
                return NULL;;
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
                break;
        }
        
        slow = head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};
