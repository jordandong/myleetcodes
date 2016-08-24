/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
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
 
//Two Queues
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        vector<int> l;
        queue<TreeNode*> q[2];
        int c = 0;

        if(root)
            q[c].push(root);
        while(q[c].size()){
            TreeNode *t = q[c].front();
            q[c].pop();
            l.push_back(t->val);
            if(t->left)
                q[c^1].push(t->left);
            if(t->right)
                q[c^1].push(t->right);
            if(q[c].empty()){
                res.push_back(l);
                c ^= 1;
                l.clear();
            }
        }
        return res;
    }
};

//One queue
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        vector<int> l;
        queue<TreeNode*> q;
        int currNum = 1;
        int nextNum = 0;
        if(root)
        	q.push(root);

        while (q.size()){
            TreeNode* t = q.front();
            q.pop();
            currNum--;
            l.push_back(t->val);
            if(t->left){
                q.push(t->left);
                nextNum++;
            }
            if(t->right){
                q.push(t->right);
                nextNum++;
            }
            if(currNum == 0) {
                res.push_back(l);
                l.clear();
                currNum = nextNum;
                nextNum = 0;
            }
        }
        return res;
    }
};
