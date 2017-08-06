/*
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
Example 2:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False
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
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, bool> mp;
        return findTargetHelper(root, k, mp);
    }
    
    bool findTargetHelper(TreeNode* root, int k, unordered_map<int, bool> &mp) {
        if (!root)
            return false;
        
        if (findTargetHelper(root->left, k, mp))
            return true;
        if (mp.find(k - root->val) != mp.end())
            return true;
        mp[root->val] = true;
        if (findTargetHelper(root->right, k, mp))
            return true;
        return false;
    }
};
