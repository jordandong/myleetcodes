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
