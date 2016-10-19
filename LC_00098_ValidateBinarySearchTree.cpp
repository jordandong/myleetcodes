/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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

//pre-order with updating min and max T : O(N)
class Solution {
public:
    bool isValidBST(TreeNode* root){
        long long mi = (long long)INT_MIN - 1;
        long long mx = (long long)INT_MAX + 1;
        return isValidBSTHelper(root, mi, mx);
    }

    bool isValidBSTHelper(TreeNode* root, long long mi, long long mx) {
        if(!root)
            return true;
        if(mi < root->val && root->val < mx) 
            return isValidBSTHelper(root->left, mi, root->val) && isValidBSTHelper(root->right, root->val, mx);
        return false;
    }
};
 
//in-order and check if it is no-decreasing, T : O(N)
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        long long pre_val = (long long)INT_MIN - 1;
        return isValidBSTHelper(root, pre_val);
    }
    
    bool isValidBSTHelper(TreeNode *root, long long &pre_val){
        if(!root)
            return true;
        bool ret;
        ret = isValidBSTHelper(root->left, pre_val);
        if(ret == false || pre_val >= root->val)
            return false;
        pre_val = root->val;
        ret = isValidBSTHelper(root->right, pre_val);
        return ret;
    }
};
