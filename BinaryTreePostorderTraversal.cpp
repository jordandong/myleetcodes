/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> stk;
        stack<bool> visited;
        stk.push(root);
        visited.push(false);
        while(stk.size()){
            TreeNode* cur = stk.top();
            bool v = visited.top();
            stk.pop();
            visited.pop();
            if(!cur || v){
                if(v)
                    res.push_back(cur->val);
                continue;
            }
            stk.push(cur);
            visited.push(true);
            stk.push(cur->right);
            visited.push(false);
            stk.push(cur->left);
            visited.push(false);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> stk;
        set<TreeNode*> st;
        while(stk.size() || root){
            while(root){
                stk.push(root);
                root = root->left;
            }
            
            root = stk.top();
            while(st.find(root) != st.end()){
                stk.pop();
                res.push_back(root->val);
                if(stk.size())
                    root = stk.top();
                else
                    return res;
            }
            st.insert(root);
            root = root->right;
        }
        return res;
    }
};
 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        postorderTraversalHelper(root, res);
        return res;
    }
    
    void postorderTraversalHelper(TreeNode *root, vector<int> &res){
        if(!root)
            return;
        postorderTraversalHelper(root->left, res);
        postorderTraversalHelper(root->right, res);
        res.push_back(root->val);
    }
};
