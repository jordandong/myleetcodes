/*
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
Note: There are at least two nodes in this BST.
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
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        TreeNode *prev_node = NULL;
        getMinimumDifferenceHelper(root, prev_node, res);
        return res;
        
    }
private:
    void getMinimumDifferenceHelper(TreeNode* root, TreeNode* &prev_node, int &res) {
        if (!root)
            return;
        getMinimumDifferenceHelper(root->left, prev_node, res);
        if (prev_node)
            res = min(res, root->val - prev_node->val);
        prev_node = root;
        getMinimumDifferenceHelper(root->right, prev_node, res);
    }
    
};
