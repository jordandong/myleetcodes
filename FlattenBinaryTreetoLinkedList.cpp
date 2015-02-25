/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

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
    void flatten(TreeNode *root) {
        TreeNode* cur = new TreeNode(-1);
        TreeNode* dummy = cur;
        flattenHelper(root, cur);
        delete dummy;
    }
    
    void flattenHelper(TreeNode *root, TreeNode* &cur) {
        if(!root)
            return;
        TreeNode* leftChild = root->left;
        TreeNode* rightChild = root->right;
        cur->right = root;
        cur = cur->right;
        cur->left = NULL;
        cur->right = NULL;
        flattenHelper(leftChild, cur);
        flattenHelper(rightChild, cur);
    }
};

class Solution {
public:
    void flatten(TreeNode *root) {
        if(!root)
            return;
        TreeNode *cur = NULL;
        stack<TreeNode*> stk;
        stk.push(root);
        while(stk.size()) {
            TreeNode* t = stk.top();
            stk.pop();
            if(t->right){
                stk.push(t->right);
                t->right = NULL;
            }
            if(t->left){
            	stk.push(t->left);
            	t->left = NULL;
            }
            if(!cur){
            	cur = t;
            }else{
            	cur->right = t;
            	cur = cur->right;
            }
        }
    }
};
