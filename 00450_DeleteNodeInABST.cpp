/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST.
Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:
1. Search for a node to remove.
2. If the node is found, delete the node.

Note: Time complexity should be O(height of tree).

Example:
root = [5,3,6,2,4,null,7]
key = 3
    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.
    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].
    5
   / \
  2   6
   \   \
    4   7

Hide Tags Tree
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
        deleteNodeHelper(root, key);
        return root;
    }
private:
    void deleteNodeHelper(TreeNode* &root, int key) {
        if (!root)
            return;
        if (root->val > key) {
		    deleteNodeHelper(root->left, key); //go left
        } else if (root->val < key) {
		    deleteNodeHelper(root->right, key); //go right
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
				    deleteNodeHelper(parent->left, parent->left->val);
			    else
				    deleteNodeHelper(root->right, root->right->val);
		    }
	    }
    }
};
