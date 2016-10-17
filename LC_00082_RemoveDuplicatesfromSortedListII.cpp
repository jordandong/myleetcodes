/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        ListNode* cur = head;
        bool found = false;
        while(cur){
            if(cur->next && cur->val == cur->next->val){
                ListNode* tmp = cur;
                cur = cur->next;
                delete tmp;
                found = true;
                continue;
            }
            if(found){
                ListNode* tmp = cur;
                cur = cur->next;
                delete tmp;
                found = false;
                continue;
            }
            tail->next = cur;
            tail = tail->next;
            cur = cur->next;
        }
        tail->next = cur;
        cur = dummy->next;
        delete dummy;
        return cur;
    }
};
