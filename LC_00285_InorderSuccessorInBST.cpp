/*
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

Note: If the given node has no in-order successor in the tree, return null.
*/

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        //case 1:
        if (p->right)
            return leftMost(p->right);
        //case 2:
        TreeNode* suc = NULL;
        while (root) {
            if (p->val < root->val) {
                suc = root;
                root = root->left;
            } else if (p->val > root->val)
                root = root->right; 
            else
                break;
        }
        return suc;
    }
private:
    TreeNode* leftMost(TreeNode* node) {
        while (node -> left)
            node = node -> left;
        return node;
    }
};
