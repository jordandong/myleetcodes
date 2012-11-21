//============================================================================
// Remove Duplicates from Sorted List
// Given a sorted linked list, delete all duplicates such that each element
// appear only once.
//
// For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3.
//============================================================================


class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
            
        ListNode *curpos = head;
        ListNode *unipos = head;
        while(curpos!=NULL){
            curpos=curpos->next; 
            while(curpos!=NULL&&curpos->val == unipos->val){
                ListNode* tmp = curpos; 
                curpos = curpos->next;
                delete tmp;
            }
            unipos->next =curpos;
            unipos=unipos->next;        
        }
        return head;
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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (NULL == head)
        	return NULL;
        ListNode* curNode = head;
        while(NULL != curNode->next) {
            if(curNode->val == curNode->next->val) {
                ListNode* nextNode = curNode->next;
                curNode->next = nextNode->next;
                delete nextNode;
            }
            else
            	curNode = curNode->next;
        }
        return head;
    }
};

int main() {
    return 0;
}
