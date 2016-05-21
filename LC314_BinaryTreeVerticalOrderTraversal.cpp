/*
Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).
If two nodes are in the same row and column, the order should be from left to right.

Examples:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its vertical order traversal as:
[
  [9],
  [3,15],
  [20],
  [7]
]
 
Given binary tree [3,9,20,4,5,2,7],
    _3_
   /   \
  9    20
 / \   / \
4   5 2   7
return its vertical order traversal as:
[
  [4],
  [9],
  [3,5,2],
  [20],
  [7]
]
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        unordered_map<int, vector<int>> cols;
        vector<pair<TreeNode *, int>> queue { {root, 0} };
        int min_idx = INT_MAX, max_idx = INT_MIN;
        for (int i = 0; i < queue.size(); ++i) {
            TreeNode *node;
            int j;
            tie(node, j) = queue[i];
            if (node) {
                cols[j].push_back(node->val);
                queue.push_back({node->left, j - 1});
                queue.push_back({node->right, j + 1});
                min_idx = min(j, min_idx);
                max_idx = max(j, max_idx);
            }
        }
        vector<vector<int>> res;
        for (int i = min_idx; !cols.empty() && i <= max_idx; ++i) {
            res.push_back(move(cols[i]));
        }
        return res;
    }
};
