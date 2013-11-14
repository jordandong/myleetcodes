/*
Sort a linked list using insertion sort.
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
    ListNode *insertionSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!head)
            return NULL;
        ListNode *sorted_head= new ListNode(-1);
        ListNode *unsorted = head;
        while(unsorted){
            ListNode *u_tmp = unsorted;
            unsorted = unsorted->next;
            u_tmp->next = NULL;
            ListNode *last_s_tmp = sorted_head;
            ListNode *s_tmp = last_s_tmp->next;
            if(!s_tmp){
                sorted_head->next = u_tmp;
                continue;
            }
            while(s_tmp){
                if(s_tmp->val<=u_tmp->val){
                    last_s_tmp = s_tmp;
                    s_tmp = s_tmp->next;
                }else{
                    last_s_tmp->next = u_tmp;
                    u_tmp->next = s_tmp;
                    break;
                }
            }
            last_s_tmp->next = u_tmp;
            u_tmp->next = s_tmp;
        }
        return sorted_head->next;
    }
};
