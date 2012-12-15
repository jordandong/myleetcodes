//============================================================================
// Recover Binary Search Tree
// Two elements of a binary search tree (BST) are swapped by mistake.
//
// Recover the tree without changing its structure.
//============================================================================

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
    
    TreeNode *l;
    TreeNode *r;
    TreeNode *p;
    
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        l=NULL;
        r=NULL;
        p=NULL;
        rT(root);
        swap(l->val, r->val);
    }
    
    void rT(TreeNode *root){
        if(root==NULL)
            return;
        rT(root->left);
        if(p!=NULL&&root->val<p->val){
            if(l==NULL)
                l=p;
            r=root;
        }
        p=root;
        rT(root->right);
    }
};


#include <iostream>
using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode *prev = NULL, *first = NULL, *second = NULL;
        recoverTreeHelper(root, prev, first, second);
        swap(first->val, second->val);
    }

    void recoverTreeHelper(TreeNode *curNode, TreeNode *&preNode, TreeNode *&first, TreeNode *&second) {
        if (curNode == NULL)
        	return;
        recoverTreeHelper(curNode->left, preNode, first, second);
        if (preNode && preNode->val > curNode->val) {
            if (first == NULL)
            	first = preNode;
            second = curNode;
        }
        preNode = curNode;
        recoverTreeHelper(curNode->right, preNode, first, second);
    }
};

int main() {
    return 0;
}
