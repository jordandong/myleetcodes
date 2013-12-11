//============================================================================
// Remove Nth Node From End of List
// Given a linked list, remove the nth node from the end of list and return
// its head.
//
// For example,
//
// Given linked list: 1->2->3->4->5, and n = 2.
//
// After removing the second node from the end, the linked list becomes
// 1->2->3->5.
// Note:
// Given n will always be valid.
// Try to do this in one pass.
//============================================================================

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *new_head = new ListNode(-1);
        new_head->next = head;
        ListNode *fast = new_head;
        ListNode *slow = new_head;
        while(n>0){
            fast=fast->next;
            n--;
        }
        
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next = slow->next->next;
        return new_head->next;
    }
};



#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (NULL == head)
        	return head;
        ListNode *fast = head;
		ListNode *slow = head;
        int i = 0;
        while (fast != NULL && i < n){
        	fast = fast->next;
			i++;
		}
        if (fast == NULL) {
            head = head->next;
            delete slow;
            return head;
        }
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* node = slow->next;
        slow->next = node->next;
        delete node;
        return head;
    }
};

int main() {
    return 0;
}
