/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:
   1
 /   \
2     3
 \
  5

All root-to-leaf paths are:
["1->2->5", "1->3"]

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Hide Tags Tree
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string sol;
        binaryTreePathsHelper(root, sol, res);
        return res;
    }
    
    void binaryTreePathsHelper(TreeNode* root, string &sol, vector<string> &res) {
        if(root == NULL)
            return;

        int pos = sol.length();
        sol += to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            res.push_back(sol);
            sol.erase(pos, sol.length() - pos);
            return;
        }
        sol += "->";
        binaryTreePathsHelper(root->left, sol, res);
        binaryTreePathsHelper(root->right, sol, res);
        sol.erase(pos, sol.length() - pos);
    }
};
