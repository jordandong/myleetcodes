/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.
Determine the maximum amount of money the thief can rob tonight without alerting the police.
Example 1:
     3
    / \
   2   3
    \   \ 
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

Example 2:
     3
    / \
   4   5
  / \   \ 
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Tags
Tree Depth-first Search
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
    int rob(TreeNode* root) {
        vector<int> res = robHelper(root);
        return max(res[0], res[1]);
    }
    
    //{rob at root, no rob at root}
    vector<int> robHelper(TreeNode* root) {
        if (!root)
            return {0, 0};
        vector<int> l = robHelper(root->left);
        vector<int> r = robHelper(root->right);
        return {root->val + l[1] + r[1], max(l[0], l[1]) + max(r[0], r[1])};
    }
};
