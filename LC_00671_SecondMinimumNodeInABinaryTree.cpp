/*
Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node.
If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

Example 1:
Input: 
    2
   / \
  2   5
     / \
    5   7
Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.

Example 2:
Input: 
    2
   / \
  2   2
Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//T : O(logN ~ N)
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(!root->left && !root->right)
            return -1;
        
        int l = (root->left->val == root->val) ? findSecondMinimumValue(root->left) : root->left->val;
        int r = (root->right->val == root->val) ? findSecondMinimumValue(root->right) : root->right->val;
        return (l == -1 || r == -1) ? max(l, r) : min(l, r);
    }
};

//T : O(N)
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        int f = -1, s = -1;
        findSecondMinimumValueHelper(root, f ,s);
        return s;
    }
    
    void findSecondMinimumValueHelper(TreeNode* root, int &f, int &s) {
        if (!root)
            return;
        findSecondMinimumValueHelper(root->left, f, s);
        
        if (f == -1 || root->val <= f) {
            if (root->val != f)
                s = f;
            f = root->val;
        } else if (s == -1 || root->val < s)
            s = root->val;
        
        findSecondMinimumValueHelper(root->right, f, s);
        
    }
};
