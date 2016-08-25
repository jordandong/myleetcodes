/*
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
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
    int closestValue(TreeNode* root, double target) {
        if (!root)
            return INT_MAX;
        if (!(root -> left) && !(root -> right))
            return root -> val;
        int left = closestValue(root -> left, target);
        int right = closestValue(root -> right, target);
        double td = abs(root -> val - target), ld = abs(left - target), rd = abs(right - target);
        if (td < ld)
            return td < rd ? root -> val : right;
        else
            return ld < rd ? left : right;
    }
};

//T : O(logN or h) , S : O(1)
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        double gap = DBL_MAX;
        int closest = INT_MAX;
        
        while (root) {
            if (abs(static_cast<double>(root->val) - target) < gap) {
                gap = abs(root->val - target);
                closest = root->val;
            }
            if (target == root->val) {
                break;
            } else if (target < root->val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return closest;
    }
};
