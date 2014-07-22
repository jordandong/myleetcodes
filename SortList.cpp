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
 
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 //Save time by avoiding counting every time
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        ListNode *count = head;
        int len = 0;
        while(count){
            count=count->next;
            len++;
        }
        return Sort(&head, len);
    }
    
    ListNode* Sort(ListNode** head, int len){
        if(len == 0)
            return NULL;
        if(len == 1){
            ListNode *tmp = *head;
            *head = (*head)->next;
            tmp->next = NULL;
            return tmp;
        }
        return Merge(Sort(head, len/2), Sort(head, len-len/2));
    }
    
    ListNode* Merge(ListNode* l1, ListNode* l2){
        ListNode *rtn_head = new ListNode(-1);
        ListNode *cur = rtn_head;
        while(l1 && l2){
            if(l1->val<l2->val){
                cur->next = l1;
                l1 = l1->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur=cur->next;
        }
        cur->next = l1?l1:l2;
        cur = rtn_head->next;
        delete rtn_head;
        return cur;
    }
};
 
 
 
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
