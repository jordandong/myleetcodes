//============================================================================
// Same Tree
// Given two binary trees, write a function to check if they are equal or not.
//
// Two binary trees are considered equal if they are structurally identical
// and the nodes have the same value.
//============================================================================

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return compare(p, q);
    }
    
    bool compare(TreeNode *p, TreeNode *q){
        if(p==NULL&&q==NULL)
            return true;
        else if (p==NULL||q==NULL)
            return false;        
        if(p->val!=q->val){
            return false;
        }else{
            return compare(p->left, q->left)&&compare(p->right, q->right);
        }
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == NULL || q == NULL)
        	return p == q;
        if (p->val != q->val)
        	return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    return 0;
}
