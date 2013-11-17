/*
Sort a linked list in O(n log n) time using constant space complexity.
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
    ListNode *sortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!head||!head->next)
            return head;
        
        ListNode *fast=head;
        ListNode *slow=head;
    
        while(fast){
            fast=fast->next;
            if(fast){
                fast=fast->next;
                if(fast)
                    slow=slow->next;
                else{
                    ListNode* tmp = slow->next;
                    slow->next = NULL;
                    slow = tmp;    
                }
            }else{
                ListNode* tmp = slow->next;
                slow->next = NULL;
                slow = tmp;
            }
        }
        
        return mergeList(sortList(head), sortList(slow));
    }
    
    ListNode *mergeList(ListNode *l1, ListNode *l2){
        ListNode *new_t = NULL;;
        ListNode *t = NULL;;
        while(l1 || l2){
            if(l1&&l2){
                if(l1->val < l2->val){
                    if(!t){
                        t=l1;
                        new_t=t;
                    }else{
                        t->next=l1;
                        t=t->next;
                    }
                    l1=l1->next;
                }else{
                    if(!t){
                        t=l2;
                        new_t=t;
                    }else{
                        t->next=l2;
                        t=t->next;
                    }
                    l2=l2->next;
                }
                continue;
            }
            if(!l1&&l2){
                t->next=l2;
                break;
            }
            if(l1&&!l2){
                t->next=l1;
                break;
            }
        }
        return new_t;
    }
};
