/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

Hide Tags Depth-first Search Linked List
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
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        int len = 0;
        ListNode* tmp = head;
        while(tmp){
            len++;
            tmp = tmp->next;
        }
        return sortedListToBSTHelper(1, len, head);
    }
    
    TreeNode* sortedListToBSTHelper(int start, int end, ListNode* &head){
        if(start > end)
            return NULL;
        int mid = start + (end - start)/2;
        TreeNode* left = sortedListToBSTHelper(start, mid - 1, head);
        TreeNode* cur = new TreeNode(head->val);
        head = head->next;
        TreeNode* right = sortedListToBSTHelper(mid + 1, end, head);
        cur->left = left;
        cur->right = right;
        return cur;
    }
};
