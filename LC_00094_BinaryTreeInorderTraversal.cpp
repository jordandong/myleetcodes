/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
Hide Tags Tree Hash Table Stack
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

//Non Recursion
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* cur = stk.top();
            stk.pop();
            if(!cur){//NULL, visit elements
                if(!stk.empty()){
                    res.push_back(stk.top()->val);
                    stk.pop();
                }
            }else{//not NULL, add elements
                stk.push(cur->right);
                stk.push(cur);
                stk.push(cur->left);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if(root == NULL)
            return res;
        stack<TreeNode*> stk;//no NULL is stack
        TreeNode* cur = root;
        while (!stk.empty() || cur != NULL) {
            if(cur != NULL){//not NULL, add
                stk.push(cur);
                cur = cur->left;
            }else{//NULL, output
                cur = stk.top();
                stk.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> stk;//not NULL in stack
        TreeNode* cur = root; 
        while(cur){
            stk.push(cur);//add element
            cur = cur->left;
            while(!cur && stk.size()){//NULL, output
                TreeNode* tmp = stk.top();
                stk.pop();
                res.push_back(tmp->val);
                cur = tmp->right;
            }
        }
        return res;
    }
};
 
//Recursion
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        inorderTraversalHelper(root, res);
        return res;
    }
    void inorderTraversalHelper(TreeNode *root, vector<int> &res){
        if(!root)
            return;
        inorderTraversalHelper(root->left, res);
        res.push_back(root->val);
        inorderTraversalHelper(root->right, res);
    }
};
