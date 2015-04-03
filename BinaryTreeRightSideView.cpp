/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].

Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.

Hide Tags Tree Depth-first Search Breadth-first Search
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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        rightSideViewHelper(root, 0, res);
        return res;
    }
  
    void rightSideViewHelper(TreeNode *root, int lv, vector<int> &res) {
        if(!root)
            return;
        if(lv == res.size())
            res.push_back(root->val);
        rightSideViewHelper(root->right, lv + 1, res);
        rightSideViewHelper(root->left, lv + 1, res);
    }
};
