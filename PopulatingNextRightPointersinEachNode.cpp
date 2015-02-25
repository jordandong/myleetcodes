/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL

Hide Tags Tree Depth-first Search
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
//DFS
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        root->next = NULL;
        connectHelper(root);
    }
    
    void connectHelper(TreeLinkNode *root){
        if(!root)
            return;
        if(root->left){
            root->left->next = root->right?root->right:NULL;
        }
        if(root->right){
            root->right->next = root->next?root->next->left:NULL;
        }
        connectHelper(root->left);
        connectHelper(root->right);
    }
};

//BFS
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        root->next = NULL;
        connectHelper(root);
    }
    
    void connectHelper(TreeLinkNode *root){
        if(!root->left || !root->right)
            return;
        
        TreeLinkNode* cur = root;
        while(cur){
            if(cur->left)
            	cur->left->next = cur->right;
            if(cur->right)
            	cur->right->next = (cur->next) ? cur->next->left : NULL;
            cur = cur->next;
        }   
        connectHelper(root->left);
    }
};
