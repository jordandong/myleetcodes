/*
Given a binary tree, return all duplicate subtrees.
For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with same node values.
Example 1: 
        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
The following are two duplicate subtrees:
      2
     /
    4
and
    4
Therefore, you need to return above trees' root in the form of a list.
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
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> mp;
        vector<TreeNode*> res;
        findDuplicateSubtreesHelper(root, mp, res);
        return res;
    }
    
    string findDuplicateSubtreesHelper(TreeNode* root, unordered_map<string, int> &mp, vector<TreeNode*> &res) {
        if (!root)
            return "#";
        
        string key = findDuplicateSubtreesHelper(root->left, mp, res)
                    + findDuplicateSubtreesHelper(root->right, mp, res)
                    + to_string(root->val);

        if (mp.find(key) == mp.end())
            mp[key] = 1;
        else if (mp[key]++ == 1)
            res.push_back(root);
        
        return key;
    }
};

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, pair<int, int>> mp;
        vector<TreeNode*> res;
        int idx = 0;
        findDuplicateSubtreesHelper(root, mp, idx, res);
        return res;
    }
    
    int findDuplicateSubtreesHelper(TreeNode* root, unordered_map<string, pair<int, int>> &mp, int &idx, vector<TreeNode*> &res) {
        if (!root)
            return 0;
        
        string key = to_string(findDuplicateSubtreesHelper(root->left, mp, idx, res))
                    + to_string(findDuplicateSubtreesHelper(root->right, mp, idx, res))
                    + to_string(root->val);

        if (mp.find(key) == mp.end())
            mp[key] = {++idx, 1};
        else if (mp[key].second++ == 1)
            res.push_back(root);
        
        return mp[key].first;
    }
};
