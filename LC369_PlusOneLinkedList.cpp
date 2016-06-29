/*
Given a non-negative number represented as a singly linked list of digits, plus one to the number.
The digits are stored such that the most significant digit is at the head of the list.

Example:
Input:
1->2->3

Output:
1->2->4
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

//T : O(N), S : O(N) 
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        int carry  = plusOneHelper(head);
        if (carry > 0 && head) {
            ListNode* new_head = new ListNode(carry);
            new_head->next = head;
            return new_head;
        }
        return head;
    }

    int plusOneHelper(ListNode* head) {
        if (!head)
            return 1;
        int carry = plusOneHelper(head->next);
        if (carry > 0) {
            head->val += carry;
            carry = head->val / 10;
            head->val %= 10;
        }
        return carry;
    }
};

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
