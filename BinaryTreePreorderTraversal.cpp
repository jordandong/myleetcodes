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
        vector<int> rtn;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* cur = stk.top();
            stk.pop();
            if(!cur)
                continue;
            rtn.push_back(cur->val);
            stk.push(cur->right);
            stk.push(cur->left);
        }
        return rtn;
    }
};


class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> s;
        //preorderHelper(root, s);
        preorderHelper1(root, s);
        return s;
    }
    
    void preorderHelper(TreeNode *root, vector<int> &s){
        if(!root)
            return;
        s.push_back(root->val);
        preorderHelper(root->left, s);
        preorderHelper(root->right, s);
    }
    
    void preorderHelper1(TreeNode *root, vector<int> &s){
        stack<TreeNode*> stk;
        while(!stk.empty() || root){
            while(root){
                s.push_back(root->val);
                stk.push(root->right);
                root=root->left;
            }            
            root = stk.top();
            stk.pop();
        }
    }
};
