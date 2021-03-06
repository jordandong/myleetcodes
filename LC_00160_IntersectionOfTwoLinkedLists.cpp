/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Credits:
Special thanks to @stellari for adding this problem and creating all test cases.

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
 
 /*
 A: aaaaaccccc bbb ccccc
 B: bbbccccc aaaaa ccccc
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA;
        ListNode *b = headB;
        bool done_a = false;
        bool done_b = false;
        if(!a || !b)
            return NULL;
            
        while(a != b){
            a = a->next;
            b = b->next;
            if(!a && !done_a){
                a = headB;
                done_a = true;
            }
            if(!b && !done_b){
                b = headA;
                done_b = true;
            }
        }
        return a;
    }
};

//find circle
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *slow = headB;
        ListNode *fast = headB;
        ListNode* tail = headA;
        if(!headA || !headB)
            return NULL;
        while(tail->next)
            tail = tail->next;

        tail->next = headA;
        
        while(slow && fast){//find circle
            slow = slow->next;
            fast = fast->next;
            if(fast)
                fast=fast->next;
            if(slow == fast){
                break;
            }
        }
        
        if(!fast){//if no circle
            tail->next = NULL;
            return NULL;
        }
        
        fast = headB;//if circle, find intersection
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        tail->next = NULL;
        return slow;
    }
};
