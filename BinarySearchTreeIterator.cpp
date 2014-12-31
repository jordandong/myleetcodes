/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in O(1) time and uses O(h) memory, where h is the height of the tree.
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
class BSTIterator {
private:
    stack<TreeNode*> h;
    
public:
    BSTIterator(TreeNode *root) {
        while(root){
            h.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !h.empty();
    }

    /** @return the next smallest number */
    int next() {
        int r = h.top()->val;
        preNext();
        return r;
    }
    
    void preNext(){
        TreeNode* t = h.top();
        h.pop();
        if(t->right){
            t=t->right;
            while(t){
                h.push(t);
                t = t->left;
            }
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
