//============================================================================
// You are given two linked lists representing two non-negative numbers.
// The digits are stored in reverse order and each of their nodes contain a
// single digit. Add the two numbers and return it as a linked list.
//
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
//============================================================================

#include <cstdlib>
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *l3 = NULL, *node = NULL;
        int c = 0;
        while (true) {
            int a, b;
            if (l1 != NULL) {
                a = l1->val;
                l1 = l1->next;
            }
            else
            	a = 0;
            if (l2 != NULL) {
                b = l2->val;
                l2 = l2->next;
            }
            else
            	b = 0;
            int s = a + b + c;
            c = s / 10;
            if (l3 == NULL)
            	l3 = node = new ListNode(s % 10);
            else
            	node->next = new ListNode(s % 10), node = node->next;
            if (l1 == NULL && l2 == NULL)
            	break;
        }
        if (c == 1)
        	node->next = new ListNode(1);
        return l3;
    }
};

int main() {
    return 0;
}





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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return addTwo(l1,l2,0);
    }
    
    ListNode *addTwo(ListNode *l1, ListNode *l2, int carry){
        
        if(l1==NULL&&l2==NULL){
            if(carry){   
                ListNode* listnode = new ListNode(carry);
                //listnode->val = carry;
                listnode->next=NULL;
                return listnode;
            }
            else{
                return NULL;
            }
        }

        if(l1!=NULL&&l2==NULL){
            if(carry){   
                int res = l1->val + carry;
                carry = res/10;
                ListNode* listnode = new ListNode(res%10);
                //listnode->val = res%10;
                listnode->next = addTwo(l1->next,NULL, carry);
                return listnode;
            }
            else{
                return l1;
            }
        }
        
        if(l1==NULL&&l2!=NULL){
            if(carry){   
                int res = l2->val + carry;
                carry = res/10;
                ListNode* listnode = new ListNode(res%10);
                //listnode->val = res%10;
                listnode->next = addTwo(NULL, l2->next, carry);
                return listnode;
            }
            else{
                return l2;
            }
        }

        
        if(l1!=NULL&&l2!=NULL){
            int res = l1->val + l2->val + carry;
            carry = res/10;
            ListNode* listnode = new ListNode(res%10);
            //listnode->val = res%10;
            listnode->next = addTwo(l1->next, l2->next, carry);
            return listnode;
        }
    }
};
