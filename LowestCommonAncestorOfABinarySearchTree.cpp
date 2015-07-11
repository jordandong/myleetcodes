/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
         
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int lca_count = 0;
        TreeNode* res = LCAHelper(root, p, q, lca_count);
        return lca_count == 2 ? res : NULL;

    }
    
    TreeNode* LCAHelper(TreeNode *root, TreeNode *A, TreeNode *B, int &lca_count){
        if (!root)
            return NULL;
        
        TreeNode* left_rtn = LCAHelper(root->left, A, B, lca_count);
        if (lca_count == 2 && left_rtn) // avoid the unecessary search after we found two
            return left_rtn;

        TreeNode* right_rtn = LCAHelper(root->right, A, B, lca_count);
        if(left_rtn && right_rtn){
            return root;
        }else if(root->val == A->val || root->val == B->val){
            if(root->val == A->val && root->val == B->val)
                lca_count++;
            lca_count++;
            return root;
        }else{
            return left_rtn ? left_rtn : right_rtn;
        }    
    }
};
