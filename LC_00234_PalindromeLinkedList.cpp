/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

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

//T: O(N) S:O(1)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* rvt = NULL;
        
        while (fast && fast->next) {
            fast = fast->next->next;
            if (rvt == NULL) {
                rvt = slow;
                slow = slow->next;
                rvt->next = NULL;
            } else {
                ListNode* tmp = slow->next;
                slow->next = rvt;
                rvt = slow;
                slow = tmp;
            }

        }
        
        if (fast)
            slow = slow->next;
            
        while (slow && rvt && slow->val == rvt->val) {
            rvt = rvt->next;
            slow = slow->next;
        }

        return !slow && !rvt;
    }
};
 
// T: O(N) S: O(N)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        stack<ListNode*> stk;
        
        while (fast && fast->next) {
            stk.push(slow);
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (fast)
            slow = slow->next;
            
        while (stk.size() && slow->val == stk.top()->val) {
            stk.pop();
            slow = slow->next;
        }

        return stk.empty();
    }
};
