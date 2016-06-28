/*
TBD
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stack>
#include <queue>
#include <map>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// T : O(3*N), S : O(1)
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        ListNode* rev_head = reverseList(head);

        ListNode* curr = rev_head;
        int carry = 1;
        while (curr && carry) {
            curr->val += carry;
            carry = curr->val / 10;
            curr->val %= 10;
            if (carry && !curr->next) {
                curr->next = new ListNode(0);
            }
            curr = curr->next;
        }

        return reverseList(rev_head);
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = NULL;
        ListNode* curr = head;

        while (curr) {
            ListNode* tmp = curr->next;
            curr->next = new_head;
            new_head = curr;
            curr = tmp;
        }

        return new_head;;
    }
};


int main () {

    ListNode* empty = NULL;
    ListNode* head = new ListNode(9);
    //head->next = new ListNode(9);
    //head->next->next = new ListNode(9);
    Solution sol;    
    ListNode* res = sol.plusOne(head);
    //ListNode* res = sol.plusOne(empty);
    while (res) {
        cout<<res->val<<" ";
        res = res->next;
    }
    cout<<endl;
    return 1;
}
