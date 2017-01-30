/*
Given a binary search tree with duplicates. You have to find all the mode(s) in given binary tree.

For example:
Given binary tree [1,null,2,2],
   1
    \
     2
    /
   2
return [2].

Note: If a tree has more than one mode, you can return them in any order.
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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        unordered_map<int, int> cnt;
        int mx = 0;
        findModeHelper(root, mx, cnt);
        for (auto &e : cnt) {
            if (e.second == mx)
                res.push_back(e.first);
        }
        return res;
    }
    
    void findModeHelper(TreeNode* root, int& mx, unordered_map<int, int>& cnt) {
        if (!root)
            return;
        mx = max(mx, ++cnt[root->val]);
        findModeHelper(root->left, mx, cnt);
        findModeHelper(root->right, mx, cnt);
    }
};
