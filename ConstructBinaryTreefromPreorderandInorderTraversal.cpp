//============================================================================
// Construct Binary Tree from Preorder and Inorder Traversal
// Given preorder and inorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.
//
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTreeHelper(preorder.begin(), inorder.begin(), preorder.size());
    }

    TreeNode *buildTreeHelper(vector<int>::iterator preorder, vector<int>::iterator inorder, size_t n) {
        if (n == 0)
        	return NULL;
        vector<int>::iterator it = find(inorder, inorder + n, *preorder);
        int idx = it - inorder;
        TreeNode* root = new TreeNode(*it);
        root->left = buildTreeHelper(preorder+1, inorder, idx);
        root->right = buildTreeHelper(preorder+idx+1, inorder+idx+1, n-idx-1);
        return root;
    }
};

int main() {
    return 0;
}



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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function  
    TreeNode *newTree = createTreeFromPreorderInorder(preorder,inorder,0,preorder.size()-1,0);
        return newTree;
    }
    
    TreeNode* createTreeFromPreorderInorder(vector<int> &preorder,vector<int> &inorder,int left,int right, int pos){
        if(left > right){
            return NULL;       
        }
        
        TreeNode *t = new TreeNode(preorder.at(pos));
        int index = search(inorder,left, right, t->val);
        t->left = createTreeFromPreorderInorder(preorder, inorder, left, index-1, pos + 1);
        t->right = createTreeFromPreorderInorder(preorder, inorder, index+1, right, pos + 1 + (index - left));
        return t;
    }

    int search(vector<int> &inorder,int left, int right,int key){
        for(int i=left; i <= right; i++){
            if( key == inorder.at(i)){
                return i;   
            }          
        }
        return  -1;
    }
};
