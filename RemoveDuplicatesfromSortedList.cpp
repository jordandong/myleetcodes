/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

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
        while(cur){
            if(cur->next && cur->val == cur->next->val){
                ListNode* tmp = cur;
                cur = cur->next;
                delete tmp;
                continue;
            }
            tail->next = cur;
            tail = tail->next;
            cur = cur->next;
        }
        cur = dummy->next;
        delete dummy;
        return cur;
    }
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head)
        	return head;
        ListNode* curNode = head;
        while(curNode->next) {
            if(curNode->val == curNode->next->val) {
                ListNode* nextNode = curNode->next;
                curNode->next = nextNode->next;
                delete nextNode;
            }else
            	curNode = curNode->next;
        }
        return head;
    }
};
