/*
Given a binary tree, find the length of the longest path where each node in the path has the same value.
This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

Example 1:
Input:
              5
             / \
            4   5
           / \   \
          1   1   5
Output:
2

Example 2:
Input:
              1
             / \
            4   5
           / \   \
          4   4   5
Output:
2

Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
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
    int longestUnivaluePath(TreeNode* root) {
        int mx = 0;
        if (root)
            longestUnivaluePathHelper(root, mx);
        return mx;
    }

private:
    int longestUnivaluePathHelper(TreeNode* node, int& mx) {
        int l = node->left ? longestUnivaluePathHelper(node->left, mx) : 0; //left side max
        int r = node->right ? longestUnivaluePathHelper(node->right, mx) : 0; //right side max
        int ll = (node->left && node->left->val == node->val) ? l + 1 : 0; //cur + left max
        int rr = (node->right && node->right->val == node->val) ? r + 1 : 0; //cur + right max
        mx = max(mx, ll + rr); //global max
        return max(ll, rr); //single side max
    }
};

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (!root)
            return 0;
        return max(longestUnivaluePathHelper(root->left, root->val) + longestUnivaluePathHelper(root->right, root->val),
            max(longestUnivaluePath(root->left), longestUnivaluePath(root->right)));
        
    }
private:
    int longestUnivaluePathHelper(TreeNode* root, int val) {
        if (!root || val != root->val)
            return 0;
        return 1 + max(longestUnivaluePathHelper(root->left, val), longestUnivaluePathHelper(root->right, val));
    }
};
