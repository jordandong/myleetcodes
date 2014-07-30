//============================================================================
// Binary Tree Inorder Traversal
// Given a binary tree, return the inorder traversal of its nodes' values.
//
// For example:
// Given binary tree {1,#,2,3},
//   1
//    \
//     2
//    /
//   3
// return [1,3,2].
//
// Note: Recursive solution is trivial, could you do it iteratively?
//
// Reference:
// http://www.leetcode.com/2010/04/binary-search-tree-in-order-traversal.html
//
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> rtn;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* cur = stk.top();
            stk.pop();
            if(!cur){
                if(!stk.empty()){
                    rtn.push_back(stk.top()->val);
                    stk.pop();
                }
                continue;
            }else{
                stk.push(cur->right);
                stk.push(cur);
                stk.push(cur->left);
            }
        }
        return rtn;
    }
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        //return inorderTraversal1(root);
        return inorderTraversal2(root);
    }

    vector<int> inorderTraversal1(TreeNode* node) {
        vector<int> result;
        inorderTraversalHelper1(node, result);
        return result;
    }

    void inorderTraversalHelper1(TreeNode* node, vector<int> &result) {
        if (node == NULL)
        	return;
        inorderTraversalHelper1(node->left, result);
        result.push_back(node->val);
        inorderTraversalHelper1(node->right, result);
    }

    vector<int> inorderTraversal2(TreeNode *node) {
        vector<int> result;
        if (node == NULL)
        		return result;
        stack<TreeNode*> stk;
        TreeNode* curr = node;
        while (!stk.empty() || curr != NULL) {
            if (curr != NULL) {
                stk.push(curr);
                curr = curr->left;
            }
            else {
                curr = stk.top();
                stk.pop();
                result.push_back(curr->val);
                curr = curr->right;
            }
        }
        return result;
    }
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        //inorderHelper(root, res);
        inorderHelperII(root, res);
        return res;
    }
    
    void inorderHelper(TreeNode* root, vector<int> &res){
        if(!root)
            return;
        inorderHelper(root->left, res);    
        res.push_back(root->val);
        inorderHelper(root->right, res);
    }
    
    void inorderHelperII(TreeNode* root, vector<int> &res){
        stack<TreeNode*> stk;
        TreeNode* curr=root; 
        while(curr){
            stk.push(curr);
            curr=curr->left;
            
            while(!curr&&stk.size()){
                TreeNode* tmp = stk.top();
                stk.pop();
                res.push_back(tmp->val);
                curr=tmp->right;
            }
        }
    }
};
