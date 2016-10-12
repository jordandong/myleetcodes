/*
Sort a linked list using insertion sort.

Hide Tags Linked List Sort
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
    ListNode *insertionSortList(ListNode *head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = NULL;
        while(head){
            cur = dummy;
            while(cur->next && cur->next->val < head->val)
                cur = cur->next;
            if(!cur->next){
                cur->next = head;
                head = head->next;
                cur->next->next = NULL;
            }else{
                ListNode* tmp = cur->next;
                cur->next = head;
                head = head->next;
                cur->next->next = tmp;
            }
        }
        cur = dummy->next;
        delete dummy;
        return cur;
    }
};
