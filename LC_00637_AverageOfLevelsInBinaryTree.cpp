/*
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7

Output: [3, 14.5, 11]

Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].

Note:
1. The range of node's value is in the range of 32-bit signed integer.
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> res;
        double sum = 0, cnt = 0;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TreeNode *t = q.front();
            q.pop();
            if (t) {
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
                sum += t->val;
                cnt++;
            } else {
               if (!q.empty())
                    q.push(NULL);
                res.push_back(sum / cnt);
                sum = 0;
                cnt = 0;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> res;
        q.push(root);
        while (!q.empty()) {
            int cnt = q.size();
            double sum = 0;
            for (int i = 0; i < cnt; i++) {
                TreeNode *t = q.front();
                q.pop();
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
                sum += t->val;
            }
            res.push_back(sum / cnt);
        }
        return res;
    }
};

