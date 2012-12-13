//============================================================================
// Binary Tree Zigzag Level Order Traversal
// Given a binary tree, return the zigzag level order traversal of its nodes'
// values. (ie, from left to right, then right to left for the next level and
// alternate between).
//
//For example:
// Given binary tree {3,9,20,#,#,15,7},
//    3
//   / \
//  9  20
//    /  \
//   15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
// ]
//============================================================================

#include <iostream>
#include <vector>
#include <stack>
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if (root == NULL)
        	return res;
        vector<int> row;
        stack<TreeNode*> currS, nextS;
        currS.push(root);
        bool leftToRight = true;
        while (!currS.empty()) {
            while (!currS.empty()) {
                TreeNode* front = currS.top();
                currS.pop();
                row.push_back(front->val);
                if (leftToRight) {
                    if (front->left)
                    	nextS.push(front->left);
                    if (front->right)
                    	nextS.push(front->right);
                }
                else {
                    if (front->right)
                    	nextS.push(front->right);
                    if (front->left)
                    	nextS.push(front->left);
                }
            }
            res.push_back(row);
            row.clear();
            swap(currS, nextS);
            leftToRight = !leftToRight;
        }
        return res;
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int> > res;
        vector<int> tmp;
        queue<TreeNode*> tmpq;
        
        if(root==NULL)
            return res;
        
        while(!q.empty()){
            TreeNode *tn = q.front();
            q.pop();
            tmp.push_back(tn->val);
            if(tn->left!=NULL)
                tmpq.push(tn->left);
            if(tn->right!=NULL)
                tmpq.push(tn->right);
                
            if(q.empty()){
                res.push_back(tmp);
                tmp.clear();
                while(!tmpq.empty()){
                    q.push(tmpq.front());
                    tmpq.pop();
                }
            }
        }
        
        vector<vector<int> > res1;
        
        for(int i=0;i<res.size();i++){
            if(i%2==0){
                res1.push_back(res.at(i));
            }
            else{
                vector<int> v = res.at(i);
                vector<int> rv;
                while(!v.empty()){
                    rv.push_back(v.back());
                    v.pop_back();
                }
                res1.push_back(rv);
            }
        }       
        
        return res1;
    }
};
