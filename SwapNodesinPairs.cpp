//============================================================================
// Swap Nodes in Pairs
// Given a linked list, swap every two adjacent nodes and return its head.
//
// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.
//
// Your algorithm should use only constant space. You may not modify the
// values in the list, only nodes itself can be changed.
//============================================================================

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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* nextNode;
        if(head&&head->next){
            nextNode=head->next;
            head->next = swapPairs(nextNode->next);
            nextNode->next=head;
        }else{
            return head;
        }
        return nextNode;
    }
};

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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<ListNode*> stk;
        ListNode* rtn=new ListNode(-1);
        ListNode* rtn_tail = rtn;
        ListNode* cur=head;
        while(cur){
            stk.push(cur);
            cur=cur->next;
            if(cur){
                stk.push(cur);
                cur=cur->next;
            }
            while(!stk.empty()){
                rtn_tail->next=stk.top();
                stk.pop();
                rtn_tail=rtn_tail->next;
            }
        }
        rtn_tail->next=cur;
        cur=rtn->next;
        delete rtn;
        return cur;
    }
};


class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *preNode = NULL;
        ListNode *curNode = head;
        while (curNode != NULL) {
            ListNode *nextNode = curNode->next;
            if (nextNode == NULL)
            	return head;
            if (preNode == NULL)
            	head = nextNode;
            else
            	preNode->next = nextNode;
            curNode->next = nextNode->next;
            nextNode->next = curNode;
            preNode = curNode;
            curNode = curNode->next;
        }
        return head;
    }
};
