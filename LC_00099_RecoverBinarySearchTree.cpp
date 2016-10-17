/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".

Hide Tags Tree Depth-first Search
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
  * first issue 5<7,  so 7(prev, store at l) must be wrong and 5(r) may be wrong
  * second issue 6>4, so 4(r) must be wrong
  */
class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode* l = NULL;
        TreeNode* r = NULL;
        TreeNode* prev = NULL;
        recoverTreeHelper(root, l, r, prev);
        swap(l->val, r->val);
    }
    
    void recoverTreeHelper(TreeNode *root, TreeNode* &l, TreeNode* &r, TreeNode* &prev){
        if(!root)
            return;
        recoverTreeHelper(root->left, l, r, prev);
        if(prev && root->val < prev->val){
            if(!l)
                l = prev;
            r = root;
        }
        prev = root;
        recoverTreeHelper(root->right, l, r, prev);
    }
};
