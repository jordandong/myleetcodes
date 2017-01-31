/*
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:
1. The left subtree of a node contains only nodes with keys less than or equal to the node's key.
2. The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
3. Both the left and right subtrees must also be binary search trees.

For example:
Given BST [1,null,2,2],
   1
    \
     2
    /
   2
return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        TreeNode* prev = NULL;
        int cnt = 0, mx = 0;
        findModeHelper(root, prev, cnt, mx, res);
        return res;
    }
private:
    void findModeHelper(TreeNode* root, TreeNode* &prev, int &cnt, int &mx, vector<int> &res) {
        if (!root)
            return;
        findModeHelper(root->left, prev, cnt, mx, res);
        if (prev && prev->val == root->val) {
            cnt++;
        }  else {
            cnt = 1;
        }
        if (cnt > mx) {
            res.clear();
            mx = cnt;
        }
        if (cnt == mx)
            res.push_back(root->val);
        prev = root;
        findModeHelper(root->right, prev, cnt, mx, res);
    }
};

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
