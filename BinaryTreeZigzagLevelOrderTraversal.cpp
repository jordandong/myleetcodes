/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
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

Hide Tags Tree Breadth-first Search Stack
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        vector<int> level;
        stack<TreeNode*> s[2];
        bool reverse = false;
        int c = 0;

        if(root)
            s[c].push(root);

        while(s[c].size()){
            TreeNode* t = s[c].top();
            s[c].pop();
            level.push_back(t->val);
            if(reverse){
                if(t->right)
                    s[c^1].push(t->right);
                if(t->left)
                    s[c^1].push(t->left);
            }else{
                if(t->left)
                    s[c^1].push(t->left);
                if(t->right)
                    s[c^1].push(t->right);
            }
            
            if(s[c].empty()){
                res.push_back(level);
                level.clear();
                c ^= 1;
                reverse=!reverse;
            }
        }
        return res;
    }
};
