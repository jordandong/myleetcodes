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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        return inorder(root, res);
    }
    
    vector<int> inorder(TreeNode *root, vector<int> &res){
        if(root==NULL)
            return res;
        res = inorder(root->left, res);
        res.push_back(root->val);
        res = inorder(root->right, res);
        
        return res;
    }
};
