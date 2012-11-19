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
