/*
Given a binary tree, find the length of the longest consecutive sequence path.
The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections.
The longest consecutive path need to be from parent to child (cannot be the reverse).

For example,
   1
    \
     3
    / \
   2   4
        \
         5
Longest consecutive sequence path is 3-4-5, so return 3.

   2
    \
     3
    / 
   2    
  / 
 1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
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
    int longestConsecutive(TreeNode* root) {
        return longest(root, NULL, 0);
    }
private:
    int longest(TreeNode* now, TreeNode* parent, int len) {
        if (!now)
            return len;
        len = (parent && now->val == parent->val + 1) ? len + 1 : 1;
        return max(len, max(longest(now->left, now, len), longest(now->right, now, len)));
    }
};
