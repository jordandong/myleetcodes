/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".

Hide Tags Tree Breadth-first Search
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        vector<int> level;
        if(!root)
            return res;
        q.push(root);
        q.push(NULL);
        while(q.size()){
            TreeNode* t = q.front();
            q.pop();
            if(t){
                level.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }else{
                res.insert(res.begin(), level);
                level.clear();
                if(q.size())
                    q.push(NULL);
            }
        }
        return res;
    }
};

//reverse uses less time
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        vector<int> level;
        if(!root)
            return res;
        q.push(root);
        q.push(NULL);
        while(q.size()){
            TreeNode* t = q.front();
            q.pop();
            if(t){
                level.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }else{
                res.push_back(level);
                level.clear();
                if(q.size())
                    q.push(NULL);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
