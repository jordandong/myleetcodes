/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

Hide Tags Tree Array Depth-first Search
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

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int sz_pre = preorder.size();
        int sz_in = inorder.size();
        if(sz_pre != sz_in || sz_pre == 0)
            return NULL;
        return buildTreeHelper(preorder, inorder, 0, 0, sz_in - 1);
    }
    
    TreeNode* buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int pre_id, int in_id_s, int in_id_e){
        if(in_id_e < in_id_s)
            return NULL;
        
        int val = preorder[pre_id];
        int found_idx = inorder_find(val, in_id_s, in_id_e, inorder);
        TreeNode* left = buildTreeHelper(preorder, inorder, pre_id + 1, in_id_s, found_idx - 1);
        TreeNode* right = buildTreeHelper(preorder, inorder, pre_id + found_idx - in_id_s + 1, found_idx + 1, in_id_e);
        TreeNode* node = new TreeNode(val);
        node->left = left;
        node->right = right;
        return node;
    }
    
    int inorder_find(int val, int s, int e, vector<int> &inorder){
        while(s <= e){
            if(inorder[s] == val)
                return s;
            else
                s++;
        }
        return  -1;
    }
};

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTreeHelper(preorder.begin(), inorder.begin(), preorder.size());
    }

    TreeNode *buildTreeHelper(auto preorder, auto inorder, int n) {
        if(n == 0)
            return NULL;
        auto it = find(inorder, inorder + n, *preorder);
        int idx = it - inorder;
        TreeNode* root = new TreeNode(*it);
        root->left = buildTreeHelper(preorder + 1, inorder, idx);
        root->right = buildTreeHelper(preorder + idx + 1, inorder + idx + 1, n - idx - 1);
        return root;
    }
};
