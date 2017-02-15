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

Hide Tags Tree Depth-first Search Breadth-first Search
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//BFS
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
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

//DFS
class Solution {
private:
    void largestValuesHelper(TreeNode* root, int depth, vector<int> &res) {
        if (!root)
            return;
        if (depth >= res.size())
            res.push_back(root->val);

        largestValuesHelper(root->left, depth + 1, res);
        largestValuesHelper(root->right, depth + 1, res);
        res[depth] = max(res[depth], root->val);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        largestValuesHelper(root, 0, res);
        return res;
    }
};
