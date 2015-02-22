/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.

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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *preTail = NULL, *curNode = head;
        ListNode *revHead = NULL, *revTail = NULL; 
        
        for(int i = 1; i <= n; i++){
            if(i ==  m - 1)
            	preTail = curNode;
            if(i == m)
            	revTail = curNode;
            if(i >= m) {
                ListNode* nextNode = curNode->next;
                curNode->next = revHead;
                revHead = curNode;
                curNode = nextNode;
            }else
                curNode = curNode->next;
        }
        
        if(preTail == NULL)
            head = revHead;
        else
            preTail->next = revHead;

        revTail->next = curNode;
        return head;
    }
};
