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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL)
            return true;
            
        int left = height(root->left);
        int right = height(root->right);
        if(left<0||right<0)
            return false;
        else if(abs(left-right)<=1)
            return true;
        else
            return false;
    }
    
    int height(TreeNode *root){
        if(root==NULL)
            return 0;
        
        int left = height(root->left);
        int right = height(root->right);
        if(left<0||right<0)
            return -1;
        else if(abs(left-right)<=1)
            return left>right?left+1:right+1;
        else
            return -1;
            
    }
};
