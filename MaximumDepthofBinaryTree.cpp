/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

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
    int maxDepth(TreeNode *root) {
        if(!root)
            return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        return 1 + max(l, r);
    }
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        int count = 0;
        int res = 0;
        maxDepthHelper(root, count, res);
        return res;
    }
    
    void maxDepthHelper(TreeNode *root, int count, int& res){
        if(root){
            count++;
            res = count>res ? count:res;
            
            maxDepthHelper(root->left, count, res);
            maxDepthHelper(root->right, count, res);
        }
    }
};
