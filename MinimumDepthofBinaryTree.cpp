//============================================================================
// Minimum Depth of Binary Tree
//
// Given a binary tree, find its minimum depth.
//
// The minimum depth is the number of nodes along the shortest path from the
// root node down to the nearest leaf node.
//============================================================================


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
            return (nl>nr?nl:nr) + 1;
        else
            return min(nl, nr) + 1;
    }
};
 
 
class Solution {
public:
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL)
            return 0;
        else if(root->left==NULL&&root->right==NULL)
            return 1;
        return min(mD(root->left), mD(root->right))+1;
    }
    
    int mD(TreeNode *root){
        if(root==NULL)
            return INT_MAX;
        if(root->left==NULL&&root->right==NULL)
            return 1;
            
        return min(mD(root->left), mD(root->right))+1;
    }
};
