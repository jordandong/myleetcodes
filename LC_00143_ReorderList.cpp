/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

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

//Non recursion
class Solution {
public:
    void reorderList(ListNode *head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = head;
        ListNode* tmp = NULL;
        
        while(fast){
            fast = fast->next;
            if(fast){
                fast = fast->next;
                slow = slow->next;
            }
        }//find the header of second half
        fast = slow->next;//fast is the header of second half
        slow->next = NULL;
        slow = NULL;

        while(fast){
            tmp = fast;
            fast = fast->next;
            tmp->next = slow;
            slow = tmp;
        }// reverse the second half, slow is the new header of second half

        fast = dummy->next;//fast is the header of the first half
        dummy->next = NULL;
        tmp = dummy;
        while(fast && slow){
            tmp->next = fast;
            tmp = tmp->next;
            fast = fast->next;
            tmp->next = slow;
            tmp = tmp->next;
            slow = slow->next;
        }//merge two lists
        if(fast)
            tmp->next = fast;
        if(slow)
            tmp->next = slow;
        delete dummy;
    }
};

//recursion, end to front
class Solution {
public:
    void reorderList(ListNode *head) {
        if(!head || !head->next)
            return;
        ListNode* slow = head, *fast = head, *first = head;
        while(fast){
            fast = fast->next;
            if(fast){
                fast=fast->next;
                slow = slow ->next;
            }
        }//now slow is the first node in the second half
        reorderListHelper(first, slow);
    }
    
    ListNode* reorderListHelper(ListNode* &first, ListNode* second){
        if(!second->next){
            ListNode* tmp = first;
            first = first->next;
            tmp->next = second;
            return second;	
        }

        ListNode* res = reorderListHelper(first, second->next);//res is the tail of the list
        if(first == second){// odd situation
            second->next = NULL;
            res->next = second;
            return second;
        }
        
        ListNode* tmp = first;
        first = first->next;
        tmp->next = second;
        second->next = NULL;
        res->next = tmp;

        return second;
    }
};
 
//recursion, front to end
class Solution {
public:
    void reorderList(ListNode *head) {
        if(!head)
            return;
        ListNode* slow = head;
        ListNode* fast = head;
        bool odd = false;
        while(fast){
            if(fast->next){
                fast=fast->next->next;
                slow = slow ->next;
            }else{
                fast=fast->next;
                odd = true;
            }
        }
        reorderListHelper(head, slow, odd);
    }
    
    ListNode* reorderListHelper(ListNode* head, ListNode* &mid, bool &odd){
        if(head == mid){
            if(odd){
                ListNode* tmp = mid;
                mid = mid->next;
                tmp->next = NULL;
                return tmp;
            }else
                return NULL;
        }
        ListNode* tmp = reorderListHelper(head->next, mid, odd);
        head->next = mid;
        mid = mid->next;
        head->next->next = tmp;
        return head;
    }
};
