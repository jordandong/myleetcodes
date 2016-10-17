/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(k==0 || k==1)
            return head;

        int len = 0;
        int rounds = 0;
        ListNode* cur = head;
        while(cur){
            len++;
            cur = cur->next;
        }
        rounds = len/k;
        if(rounds == 0)
            return head;
        
        stack<ListNode*> stk;
        ListNode *rtn = new ListNode(-1);
        ListNode *rtn_tail = rtn;
        cur = head;
        while(rounds > 0){
            for(int i = 1; i <= k; i++){
                stk.push(cur);
                cur = cur->next;
            }
            while(!stk.empty()){
                rtn_tail->next = stk.top();
                stk.pop();
                rtn_tail = rtn_tail->next;
            }
            rounds--;
        }
        rtn_tail->next = cur;
        cur = rtn->next;
        delete rtn;
        return cur;
    }
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(k == 0 || k == 1)
            return head;
        	
        ListNode *curNode = head;
        int length = 0;
        while (curNode != NULL){
            curNode = curNode->next;
            length++;
        }
        int multi = length/k;
        if(multi == 0)
            return head;

        ListNode *preTail = NULL, *curHead = NULL, *curTail = NULL;
        ListNode *preNode, *nextNode;
        curNode = head;
        for(int j = 0; j < multi; j++) {
            preNode = NULL;
            for(int i = 0; i < k; i++) {
                if(curNode != NULL) {
                    nextNode = curNode->next;
                    curNode->next = preNode;
                    preNode = curNode;
                }
                if(i == 0)
                    curTail = curNode;
                if(i == (k - 1))
                    curHead = curNode;
                curNode = nextNode;
            }
            if(preTail == NULL)
            	head = curHead;
            else
            	preTail->next = curHead;
            preTail = curTail;
        }
        curTail->next = curNode;
        return head;
    }
};
