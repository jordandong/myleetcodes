/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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

Hide Tags Tree Dynamic Programming
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
 
 //Using DP to avoid duplicated calculation and optimized space usages
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        vector<vector<void*> > dp(n + 1, vector<void*>(n + 1, NULL));
        vector<TreeNode*> res;
        res = *generateTreesHelper(1, n, dp);
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if(dp[i][j])
                    delete (vector<TreeNode*>*)dp[i][j];
            }
        }
        return res;
    }
    
    vector<TreeNode *>* generateTreesHelper(int start, int end, vector<vector<void*> > &dp){
        vector<TreeNode*>* res = new vector<TreeNode*>();
        if(start > end || start == 0){
            res->push_back(NULL);
            if(dp[0][0])//avoid allocate mem again 
                delete res;
            else
                dp[0][0] = res;
            return (vector<TreeNode*>*)dp[0][0];
        }

        if(dp[start][end])
            return (vector<TreeNode*>*)dp[start][end];
        for(int i = start; i <= end; i++){
            vector<TreeNode *> *left =  generateTreesHelper(start, i - 1, dp);
            vector<TreeNode *> *right =  generateTreesHelper(i + 1, end, dp);
            for(int l = 0; l < left->size(); l++){
                for(int r = 0; r < right->size(); r++){
                    TreeNode* node = new TreeNode(i);
                    node->left = (*left)[l];
                    node->right = (*right)[r];
                    res->push_back(node);
                }
            }
        }
        dp[start][end] = res;
        return res;
    }
};

//Non DP, optimize the memory usage
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return *generate(1, n);
    }

    vector<TreeNode *>* generate(int start, int end) {
        vector<TreeNode *> *subTree = new vector<TreeNode*>();
        vector<TreeNode*> *leftSubs;
        vector<TreeNode*> *rightSubs;
        if(start > end){
            subTree->push_back(NULL);
            return subTree;
        }
        for(int i = start; i <= end; i++){
            leftSubs = generate(start, i - 1);
            rightSubs = generate(i + 1, end);
            for(int j = 0; j < leftSubs->size(); j++){
                for(int k=0; k < rightSubs->size(); k++){
                    TreeNode *node = new TreeNode(i);
                    node->left = (*leftSubs)[j];
                    node->right = (*rightSubs)[k];
                    subTree->push_back(node);
                }
            }
        }
        delete leftSubs;
        delete rightSubs;
        return subTree;
    }
};

//Non DP, and copy many return values
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return generateTreesHelper(1, n);
    }
    
    vector<TreeNode *> generateTreesHelper(int start, int end){
        vector<TreeNode*> res;
        if(start > end || start == 0){
            res.push_back(NULL);
            return res;
        }
        
        for(int i = start; i <= end; i++){
            vector<TreeNode *> left =  generateTreesHelper(start, i-1);
            vector<TreeNode *> right =  generateTreesHelper(i+1, end);
            for(int l = 0; l < left.size(); l++){
                for(int r = 0; r < right.size(); r++){
                    TreeNode* node = new TreeNode(i);
                    node->left = left[l];
                    node->right = right[r];
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};
