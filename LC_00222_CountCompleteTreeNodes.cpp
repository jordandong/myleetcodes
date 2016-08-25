/*
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia: http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees

In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Hide Tags Tree Binary Search
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
 
//T: O(h^2) S:O(h)
class Solution {
public:
    int countNodes(TreeNode* root) {
        return countNodesHelper(root, 0, 0);
    }
    
    int countNodesHelper(TreeNode* root, int l_dep, int r_dep) {
        if (root == NULL)
            return 0;
        
        if (l_dep == 0) {
            TreeNode* tmp = root->left;
            while (tmp) {
                l_dep++;
                tmp = tmp->left;
            }
        }
        
        if (r_dep == 0) {
            TreeNode* tmp = root->right;
            while (tmp) {
                r_dep++;
                tmp = tmp->right;
            }
        }
        
        if (l_dep == r_dep)
            return pow(2, l_dep + 1) - 1;
        else
            return countNodesHelper(root->left, l_dep - 1, 0) + countNodesHelper(root->right, 0, r_dep - 1) + 1;
    }
};
