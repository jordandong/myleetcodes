/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.

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
    int maxPathSum(TreeNode *root) {
        long long res = (long long)INT_MIN - 1;
        maxPathSumHelper(root, res);
        return (int)res;
    }
    
    int maxPathSumHelper(TreeNode *root, long long &res) {
        if(!root)
            return 0;
        int left = maxPathSumHelper(root->left, res);
        int right = maxPathSumHelper(root->right, res);
        int sum = root->val;
        sum += max(left, 0);
        sum += max(right, 0);
        res = res > sum ? res : sum;
        return max(root->val + max(left, right), root->val);
    }
};
