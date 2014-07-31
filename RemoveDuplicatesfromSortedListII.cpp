//============================================================================
// Remove Duplicates from Sorted List II
// Given a sorted linked list, delete all nodes that have duplicate numbers,
// leaving only distinct numbers from the original list.
//
// For example,
// Given 1->2->3->3->4->4->5, return 1->2->5.
// Given 1->1->1->2->3, return 2->3.
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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode* rtn = new ListNode(-1);
        ListNode* rtn_tail=rtn;
        ListNode* cur=head;
        bool found = false;
        while(cur){
            if(cur->next && cur->val==cur->next->val){
                ListNode* tmp = cur;
                cur=cur->next;
                delete tmp;
                found=true;
                continue;
            }
            if(found){
                ListNode* tmp = cur;
                cur=cur->next;
                delete tmp;
                found=false;
                continue;
            }
            rtn_tail->next=cur;
            rtn_tail=rtn_tail->next;
            cur=cur->next;
        }
        rtn_tail->next=cur;
        cur=rtn->next;
        delete rtn;
        return cur;
    }
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        
        ListNode* reshead = new ListNode(0);
        reshead->next = head;
        
        ListNode* pos = reshead;
        ListNode* begin=pos->next;
        ListNode* end = begin->next;
        
        while(begin!=NULL&&end!=NULL){
            if(begin->val!=end->val){
                begin=begin->next;
                end=end->next;
                pos=pos->next;
                continue;
            }else{
                while(begin!=NULL&&end!=NULL&&begin->val==end->val){
                    end = end->next;
                }
                while(begin!=end){
                    ListNode* tmp = begin;
                    begin=begin->next;
                    delete tmp;
                }
                pos->next = begin;
                
                if(end!=NULL)
                    end=end->next;
            }
        }
        return reshead->next;
    }
};


class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL)
        	return head;
        ListNode* newHead = NULL, *newNode = NULL;
        ListNode* curNode = head;
        while (curNode != NULL) {
            bool found = true;
            ListNode* nextNode;
            while (curNode->next != NULL && curNode->val == curNode->next->val) {
                nextNode = curNode->next;
                delete curNode;
                curNode = nextNode;
                found = false;
            }
            if (found) {
                if (newHead == NULL) {
                    newHead = curNode;
                    newNode = curNode;
                }
                else {
                    newNode->next = curNode;
                    newNode = newNode->next;
                }
                curNode = curNode->next;
            }
            else {
                nextNode = curNode->next;
                delete curNode;
                curNode = nextNode;
            }
        }
        if (newNode) 
        	newNode->next = NULL;
        return newHead;
    }
};
