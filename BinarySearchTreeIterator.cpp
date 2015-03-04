/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Hide Tags Tree Stack
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
            t = t->right;
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
 
//modified the tree, O(1) space, not sure why {2, 1, 3} runtime error, it is correct on my local machine
class BSTIterator {
private:
    TreeNode* cur;
public:
    BSTIterator(TreeNode *root) {
        TreeNode* last = NULL;
        cur = root;
        preprocess(root, last);
        while(cur && cur->left)
            cur = cur->left;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cur != NULL;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* res = cur;
        cur = cur->right; // always goto next node
        while(cur && cur->left && cur->left->val > res->val) //if left node is unvisited
            cur = cur->left;
        return res->val;
    }
    
    void preprocess(TreeNode *root, TreeNode* &last){
        if(!root)
            return;
        preprocess(root->left, last);
        if(last && !last->right) // set all the right node to the next node if it is NULL
            last->right = root;
        last = root;
        preprocess(root->right, last);
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
