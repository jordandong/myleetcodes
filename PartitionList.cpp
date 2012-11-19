//============================================================================
// Partition List
// Given a linked list and a value x, partition it such that all nodes less
// than x come before nodes greater than or equal to x.
//
// You should preserve the original relative order of the nodes in each of the
// two partitions.
//
// For example,
// Given 1->4->3->2->5->2 and x = 3,
// return 1->2->2->4->3->5.
//============================================================================

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
    ListNode *partition(ListNode *head, int x) {
        ListNode* frontHead = NULL, *frontNode = NULL;
        ListNode* backHead = NULL, *backNode = NULL;
        while (head != NULL) {
            if (head->val < x) {
                if (frontHead == NULL) {
                    frontHead = head;
                    frontNode = head;
                }
                else {
                    frontNode->next = head;
                    frontNode = frontNode->next;
                }
            }
            else {
                if (backHead == NULL) {
                    backHead = head;
                    backNode = head;
                }
                else {
                    backNode->next = head;
                    backNode = backNode->next;
                }
            }
            head = head->next;
        }
        
        if (frontNode != NULL)
        	frontNode->next = backHead;
        if (backNode != NULL)
        	backNode->next = NULL;
        if (frontHead == NULL)
        	return backHead;
        
        return frontHead;
    }
};

int main() {
	return 0;
}



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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head==NULL)
            return NULL;
            
        
        ListNode *point = new ListNode(INT_MIN);
        ListNode *res = point;
        
        point->next=head;
        while(point->next!=NULL){
            if(point->next->val<x)
                point=point->next;
            else{
                break;
            }
        }
        
        ListNode *xp = point;
        
        while(xp!=NULL){
            if(xp->next!=NULL){
                if(xp->next->val < x){
                    ListNode* tmp = xp->next;
                    xp->next=tmp->next;
                    
                    tmp->next=point->next;
                    point->next = tmp;
                    point=point->next;
                }
                else{
                    xp = xp->next;
                }
            }else{
                xp=xp->next;
            }
        }
        return res->next;
    }
};
