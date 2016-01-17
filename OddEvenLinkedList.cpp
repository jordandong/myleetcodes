/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...

Credits:
Special thanks to @aadarshjajodia for adding this problem and creating all test cases.

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
 
 //T : O(N), S : O(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode *head_even = head->next;
        ListNode *tail_odd = head, *tail_even = head_even;

        while(tail_even != NULL && tail_even->next != NULL){
            tail_odd->next = tail_even->next;
            tail_odd = tail_odd->next;
            tail_even->next = tail_odd->next;
            tail_even = tail_even->next;
        }
        tail_odd->next = head_even;
        return head;
    }
};
