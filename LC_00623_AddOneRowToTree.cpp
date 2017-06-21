/*
Given the root of a binary tree, then value v and depth d, you need to add a row of nodes with value v at the given depth d.
The root node is at depth 1.

The adding rule is:
given a positive integer depth d, for each NOT null tree nodes N in depth d-1, create two tree nodes with value v as N's left subtree root and right subtree root.
And N's original left subtree should be the left subtree of the new left subtree root, its original right subtree should be the right subtree of the new right subtree root.
If depth d is 1 that means there is no depth d-1 at all, then create a tree node with value v as the new root of the whole original tree, and the original tree is the new root's left subtree.

Example 1:
Input: 
A binary tree as following:
       4
     /   \
    2     6
   / \   / 
  3   1 5   
v = 1
d = 2
Output: 
       4
      / \
     1   1
    /     \
   2       6
  / \     / 
 3   1   5   

Example 2:
Input: 
A binary tree as following:
      4
     /   
    2    
   / \   
  3   1    
v = 1
d = 3
Output: 
      4
     /   
    2
   / \    
  1   1
 /     \  
3       1

Note:
1. The given d is in range [1, maximum depth of the given tree + 1].
2. The given binary tree has at least one tree node.
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (!root)
            return root;
        if (d == 1) {
            TreeNode *rtn = new TreeNode(v);
            rtn->left = root;
            return rtn;
        }
        if (d == 2) {
            TreeNode *l = new TreeNode(v);
            TreeNode *r = new TreeNode(v);
            l->left = root->left;
            r->right = root->right;
            root->left = l;
            root->right = r;
            return root;
        }
        addOneRow(root->left, v, d - 1);
        addOneRow(root->right, v, d - 1);
        return root;
    }
};

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d < 2) {
            TreeNode* newroot = new TreeNode(v);
            (d ? newroot->left : newroot->right) = root;
            return newroot;
        }
        if (root) {
            root->left = addOneRow(root->left, v, d - 1);
            root->right = addOneRow(root->right, v, d - 1 - (d == 2));
        }
        return root;
    }
};

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (!root)
            return root;
        if (d == 1) {
            TreeNode *rtn = new TreeNode(v);
            rtn->left = root;
            return rtn;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(d-- > 2) {
            while (q.front()) {
                TreeNode *t = q.front();
                q.pop();
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            q.push(NULL);
            q.pop();
        }
        
        while (q.front()) {
            TreeNode *t = q.front();
            q.pop();
            TreeNode* l = new TreeNode(v);
            TreeNode* r = new TreeNode(v);
            l->left = t->left;
            r->right = t->right;
            t->left = l;
            t->right = r;
        }
        return root;
    }
};
