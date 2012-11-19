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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return sA(num, 0, num.size()-1);
        
    }
    
    TreeNode *sA(vector<int> &data, int left, int right){
        if(left>right)
            return NULL;
        
        int mid = (left + right+1)/2;
        TreeNode *t = new TreeNode(data[mid]);
        t->left = sA(data, left, mid-1);
        t->right = sA(data, mid+1, right);
        return t;
    }
};
