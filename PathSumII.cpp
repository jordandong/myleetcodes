//============================================================================
// Path Sum II
// Given a binary tree and a sum, find all root-to-leaf paths where each
// path's sum equals the given sum.
//
// For example:
// Given the below binary tree and sum = 22,
//              5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \    / \
//        7    2  5   1
// return
// [
//   [5,4,11,2],
//   [5,8,4,5]
// ]
//============================================================================

#include <iostream>
#include <vector>
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> path;
        vector<vector<int> > res;
        pathSumHelper(root, sum, path, res);
        return res;
    }

    void pathSumHelper(TreeNode* node, int sum, vector<int> path, vector<vector<int> > &res) {
        if (node == NULL)
        	return;
        sum -= node->val;
        path.push_back(node->val);
        
        if (sum == 0 && NULL == node->left && NULL == node->right) {
            res.push_back(path);
            return;
        }
        pathSumHelper(node->left, sum, path, res);
        pathSumHelper(node->right, sum, path, res);
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        vector<int> path;
        pS(root, sum, res, path);
        return res;
    }
    
    void pS(TreeNode *root, int sum, vector<vector<int> > &res, vector<int> &path){
        if(root==NULL)
            return;
            
        if(root->left!=NULL){
            path.push_back(root->val);
            pS(root->left, sum - root->val, res, path);
            path.pop_back();
        }
        
        if(root->right!=NULL){
            path.push_back(root->val);
            pS(root->right, sum - root->val, res, path);
            path.pop_back();
        }
        
        if(root->left==NULL&&root->right==NULL){
            if(sum - root->val==0){
                path.push_back(root->val);
                res.push_back(path);
                path.pop_back();
            }
        }
    }
};
