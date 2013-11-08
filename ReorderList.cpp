/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!head || !head->next)
            return;
        ListNode* slow = head;
        ListNode* fast = head;
        bool odd = false;
        while(fast){
            if(fast->next){
                fast=fast->next->next;
                slow = slow ->next;
            }
            else{
                fast=fast->next;
                odd = true;
            }
        }
        
        reorderListHelper(head, slow, odd);
    }
    
    ListNode* reorderListHelper(ListNode* head, ListNode* &mid, bool &odd){
        if(head==mid){
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
