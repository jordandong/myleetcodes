/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
Hide Tags Tree Depth-first Search
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> sol;
        vector<vector<int> > res;
        pathSumHelper(root, sum, sol, res);
        return res;
    }
    
    void pathSumHelper(TreeNode *root, int sum, vector<int> &sol, vector<vector<int> > &res) {
        if(root == NULL)
            return;
            
        sum -= root->val;
        sol.push_back(root->val);
        
        if(!root->left && !root->right && sum == 0)
            res.push_back(sol);
        
        pathSumHelper(root->left, sum, sol, res);
        pathSumHelper(root->right, sum, sol, res);
        sol.pop_back();
    }
};
