/*
Given a binary tree, find the maximum path sum.
The path may start and end at any node in the tree.
For example:
Given the below binary tree,
       1
      / \
     2   3
Return 6.
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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxval=-999999;
        mPT(root, maxval);
        return maxval;
        
    }
    
    int mPT(TreeNode *root, int& maxval) {
        if(root==NULL)
            return -999999;
        int left = mPT(root->left, maxval);
        int right = mPT(root->right, maxval);

        int rsum = right + root->val;
        int lsum = left + root->val;
        int sum = right + left + root->val;
        
        maxval = max(max(max(max(max(max(right,left),rsum),lsum),sum),root->val),maxval);
        
        return max(max(rsum,lsum),root->val);
    }
};

