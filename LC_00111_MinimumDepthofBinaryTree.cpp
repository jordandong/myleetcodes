/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

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
    int minDepth(TreeNode *root) {
        if(!root)
            return 0;
        int nl = minDepth(root->left);
        int nr = minDepth(root->right);
        if(nl == 0 || nr == 0)
            return (nl > nr ? nl : nr) + 1;
        else
            return min(nl, nr) + 1;
    }
};
