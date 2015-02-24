/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

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
    bool isBalanced(TreeNode *root) {
        int h;
        return isBalancedHelper(root, h);
    }
    
    bool isBalancedHelper(TreeNode *root, int &h){
        if(!root){
            h = 1;
            return true;
        }
        int l_h = 0;
        bool l = isBalancedHelper(root->left, l_h);
        if(l == false)
            return l;
        int r_h = 0;
        bool r = isBalancedHelper(root->right, r_h);
        if(r == false)
            return r;
        h = max(l_h, r_h) + 1;
        return abs(l_h - r_h) <= 1;
    }
};

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if(root==NULL)
            return true;
            
        int left = height(root->left);
        if(left < 0)
            return false;

        int right = height(root->right);
        if(right < 0)
            return false;

        if(abs(left - right) <= 1)
            return true;
        else
            return false;
    }
    
    int height(TreeNode *root){
        if(root == NULL)
            return 0;
        
        int left = height(root->left);
        if(left < 0)
            return -1;
        
        int right = height(root->right);
        if(right < 0)
            return -1;
        
        if(abs(left - right) <= 1)
            return left > right ? left + 1:right + 1;
        else
            return -1;          
    }
};
