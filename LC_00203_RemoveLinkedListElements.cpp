/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        dummy->next = head;
        while(cur && cur->next){
            if(cur->next->val == val){
                ListNode* t = cur->next;
                cur->next = t->next;
                delete t;
            }else{
                cur = cur->next;
            }
        }
        cur = dummy->next;
        delete dummy;
        return cur;
    }
};
