/*
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return NULL;
        return NULL;
        if (root->val > key) {
		    return deleteNode(root->left, key); //go left
        } else if (root->val < key) {
		    return deleteNode(root->right, key); //go right
    	} else { //found
		    if (!root->left) { //no left child
			    TreeNode* tmp = root->right;
			    delete root;
			    root = tmp;
		    } else if (!root->right) { //no right child
			    TreeNode* tmp = root->left;
			    delete root;
			    root = tmp;
		    }else{//two children
			    TreeNode *tmp = root->right;
			    TreeNode *parent = NULL;
			    while (tmp->left){ //get the smallest one among those are bigger than key
				    parent = tmp;
				    tmp = tmp->left;
			    }
			    root->val = tmp->val;
			    if (parent)
				    return deleteNode(parent->left, parent->left->val);
			    else
				    return deleteNode(root->right, root->right->val);
		    }
		    return NULL;
	    }
    }
};
