/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?

Hide Tags Tree Stack
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> stk;
        stk.push(root);
        while(stk.size()){
            TreeNode* cur = stk.top();
            stk.pop();
            if(!cur)
                continue;
            res.push_back(cur->val);
            stk.push(cur->right);
            stk.push(cur->left);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while(stk.size() || root){
            while(root){
                res.push_back(root->val);
                stk.push(root->right);
                root = root->left;
            }            
            root = stk.top();
            stk.pop();
        }
        return res;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        preorderTraversalHelper(root, res);
        return res;
    }
    
    void preorderTraversalHelper(TreeNode *root, vector<int> &res){
        if(!root)
            return;
        res.push_back(root->val);
        preorderTraversalHelper(root->left, res);
        preorderTraversalHelper(root->right, res);
    }
};
