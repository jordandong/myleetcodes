/*
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9

to
     4
   /   \
  7     2
 / \   / \
9   6 3   1

Trivia:
This problem was inspired by this original tweet by Max Howell:
Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.

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
 
 //Recursion
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return NULL;
        TreeNode *l = invertTree(root->right);
        TreeNode *r = invertTree(root->left);
        root->left = l;
        root->right = r;
        return root;
    }
};

//Non-Recursion
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            TreeNode *t = q.front();
            q.pop();
            if (!t)
                continue;
            q.push(t->left);
            q.push(t->right);
            swap(t->left, t->right);
        }
        return root;
    }
};
