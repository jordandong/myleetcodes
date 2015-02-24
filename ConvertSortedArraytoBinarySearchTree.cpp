/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

Hide Tags Tree Depth-first Search
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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBSTHelper(num, 0, num.size() - 1);
    }
    
    TreeNode* sortedArrayToBSTHelper(vector<int> &num, int s, int e){
        if(e < s)
            return NULL;
        int mid = s + (e - s)/2;
        TreeNode* node = new TreeNode(num[mid]);
        node->left = sortedArrayToBSTHelper(num, s, mid - 1);
        node->right = sortedArrayToBSTHelper(num, mid + 1, e);
        return node;
    }
};
