/*
You are given two linked lists representing two non-negative numbers. The most significant digit comes first and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:
Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7

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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 0, len2 = 0, carry = 0;
        ListNode *t = l1, *res;
        while (t) {
            len1++;
            t= t->next;
        }
        t = l2;
        while (t) {
            len2++;
            t= t->next;
        }
        
        if (len1 < len2)
            t = addTwoNumbersHelper(l2, l1, len2, len1, carry);
        else
            t = addTwoNumbersHelper(l1, l2, len1, len2, carry);
        
        if (carry) {
            res = new ListNode(1);
            res->next = t;
        } else {
            res = t;
        }
        return res;
    }
    
    ListNode* addTwoNumbersHelper(ListNode* l1, ListNode* l2, int len1, int len2, int &carry) {
        if (len1 == 0 && len2 == 0)
            return NULL;

        ListNode *t, *res;
        if (len1 != len2) {
            t = addTwoNumbersHelper(l1->next, l2, --len1, len2, carry);
            res = new ListNode((carry + l1->val) % 10);
            res->next = t;
            carry = (carry + l1->val) / 10;
        } else {
            t = addTwoNumbersHelper(l1->next, l2->next, --len1, --len2, carry);
            res = new ListNode((carry + l1->val + l2->val) % 10);
            res->next = t;
            carry = (carry + l1->val + l2->val) / 10;
        }
        return res;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 0, len2 = 0, len = 0;
        ListNode *t = l1, *res;
        while (t) {
            len1++;
            t= t->next;
        }
        t = l2;
        while (t) {
            len2++;
            t= t->next;
        }
        len = max(len1, len2);
        
        res = new ListNode(0);
        t = res;
        while (len) {
            t->next = new ListNode(0);
            t = t->next;
            if (len <= len1) {
                t->val += l1->val;
                l1 = l1->next;
            }
            if (len <= len2) {
                t->val += l2->val;
                l2 = l2->next;
            }
            len--;
        }
        
        t = res;
        while (t) {
            ListNode *q = t->next;
            while (q && q->val == 9) {
                q = q->next;
            }
            if (q && q->val > 9) {
                while (t != q) {
                    t->val += 1;
                    t = t->next;
                    t->val -= 10;
                }
            } else {
                t = q;
            }
        }
        if (res->val)
            return res;
        else
            return res->next;
    }
};
