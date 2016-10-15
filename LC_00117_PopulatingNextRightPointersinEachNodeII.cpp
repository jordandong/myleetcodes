/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

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
 
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        queue<TreeLinkNode*> q[2];
        int c = 0;
        q[c].push(root);
        while(q[c].size()){
            TreeLinkNode* t = q[c].front();
            q[c].pop();
            if(t->left)
                q[c^1].push(t->left);
            if(t->right)
                q[c^1].push(t->right);
            if(q[c].empty()){
                t->next = NULL;
                c ^= 1;
            }else{
                t->next = q[c].front();
            }
        }
    }
};

//BFS
class Solution {
public:
    void connect(TreeLinkNode *root){
        connectHelper(root);
    }
    
    void connectHelper(TreeLinkNode *root){
        if(!root)
        	return;
        TreeLinkNode* nextHead = NULL;
        while(root){
            if(root->left){
                root->left->next = getNextSibling(root, true);
                if(!nextHead)
                	nextHead = root->left;
            }
            if (root->right){
                root->right->next = getNextSibling(root, false);
                if(!nextHead)
                    nextHead = root->right;
            }
            root = root->next;
        }
        connectHelper(nextHead);
    }

    TreeLinkNode* getNextSibling(TreeLinkNode *curNode, bool isLeft){
        if (isLeft)
            if (curNode->right)
            	return curNode->right;
        while((curNode = curNode->next)){
            if(curNode->left)
            	return curNode->left;
            if(curNode->right)
            	return curNode->right;
        }
        return NULL;
    }
};
