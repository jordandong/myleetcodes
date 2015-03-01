/*
Sort a linked list in O(n log n) time using constant space complexity.

Hide Tags Linked List Sort
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
        ListNode *count = head;
        int len = 0;
        while(count){
            count = count->next;
            len++;
        }
        return Partition_Sort(head, len);
    }
    
    ListNode* Partition_Sort(ListNode* &head, int len){
        if(len == 0)
            return NULL;
        if(len == 1){
            ListNode *tmp = head;
            head = head->next;
            tmp->next = NULL;
            return tmp;
        }
        return Merge(Partition_Sort(head, len/2), Partition_Sort(head, len - len/2));
    }
    
    ListNode* Merge(ListNode* l1, ListNode* l2){
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        cur = dummy->next;
        delete dummy;
        return cur;
    }
};
