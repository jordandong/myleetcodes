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
 
 /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
 /* inorder: 1 2 3 7 5 6 4 8 9
  * first issue 5<7,  so 7(p->l) must be wrong and 5(r) may be wrong
  * second issue 6>4, so 4(r) must be wrong
  */
class Solution {
public:
    
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode* l=NULL;
        TreeNode* r=NULL;
        TreeNode* p=NULL;
        rT(root, l, r, p);
        swap(l->val, r->val);
    }
    
    void rT(TreeNode *root, TreeNode* &l, TreeNode* &r, TreeNode* &p){
        if(root==NULL)
            return;
        rT(root->left, l, r, p);
        if(p!=NULL && root->val<p->val){
            if(l==NULL)
                l=p;
            r=root;
        }
        p=root;
        rT(root->right, l, r, p);
    }
};

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
