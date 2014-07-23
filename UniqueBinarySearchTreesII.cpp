//============================================================================
// Unique Binary Search Trees II
// Given n, generate all structurally unique BST's (binary search trees) that
// store values 1...n.
//
// For example,
// Given n = 3, your program should return all 5 unique BST's shown below.
//
//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3
//============================================================================


//optimize the memory usage
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        if(n==0)
            return *generate(1, 0);
        return *generate(1, n);
    }

    vector<TreeNode *>* generate(int start, int end) {
        vector<TreeNode *> *subTree = new vector<TreeNode*>();
        vector<TreeNode*> *leftSubs;
        vector<TreeNode*> *rightSubs;
        if(start>end){
            subTree->push_back(NULL);
            return subTree;
        }
        for(int i =start; i<=end; i++){
            leftSubs = generate(start, i-1);
            rightSubs = generate(i+1, end);
            for(int j = 0; j< leftSubs->size(); j++){
                for(int k=0; k<rightSubs->size(); k++){
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
    vector<TreeNode *> generateTrees(int n) {
        return generateTreesHelper(1, n);
    }

    vector<TreeNode*> generateTreesHelper(int l, int u) {
        vector<TreeNode*> res;
        if (l > u) {
            res.push_back(NULL);
            return res;
        }
        for (int k = l; k <= u; k++) {
            vector<TreeNode*> leftTrees = generateTreesHelper(l, k-1);
            vector<TreeNode*> rightTrees = generateTreesHelper(k+1, u);
            for (int i = 0; i < leftTrees.size(); i++) {
                for (int j = 0; j < rightTrees.size(); j++) {
                    TreeNode* root = new TreeNode(k);
                    root->left = leftTrees[i];
                    root->right = rightTrees[j];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
