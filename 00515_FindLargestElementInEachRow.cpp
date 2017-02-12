/*
You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]
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
    vector<int> findValueMostElement(TreeNode* root) {
        if (!root)
            return {};
        vector<int> res;
        int mx = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (!cur) {
                res.push_back(mx);
                mx = INT_MIN;
                if (!q.empty())
                    q.push(NULL);
                continue;
            }
            mx = max(mx, cur->val);
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
        return res;
    }
};
