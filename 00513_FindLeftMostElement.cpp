/*
Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2: 
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int findLeftMostNode(TreeNode* root) {
        if (!root)
            return -1;
        int res = root->val;
        int row = -1;
        findLeftMostNodeHelper(root, 0, row, res);
        return res;
    }
private:
    void findLeftMostNodeHelper(TreeNode* root, int cur_row, int &row, int &res) {
        if (!root)
            return;
        if (cur_row > row) {
            res = root->val;
            row = cur_row;
        }
        findLeftMostNodeHelper(root->left, cur_row + 1, row, res);
        findLeftMostNodeHelper(root->right, cur_row + 1, row, res);
    }
};
