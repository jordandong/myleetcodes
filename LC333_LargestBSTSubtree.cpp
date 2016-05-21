/*
Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), 
where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.
Here's an example:

      10
    /    \
    5*    15
  /   \    \ 
 1*   8*   7
The Largest BST Subtree in this case is the highlighted one. 
The return value is the subtree's size, which is 3.

Hint:
You can recursively use algorithm similar to 98. Validate Binary Search Tree at each node of the tree, which will result in O(nlogn) time complexity.
Follow up:
Can you figure out ways to solve it with O(n) time complexity?
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
    int largestBSTSubtree(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int max_size = 1;
        largestBSTSubtreeHelper(root, &max_size);
        return max_size;
    }

private:
    tuple<int, int, int> largestBSTSubtreeHelper(TreeNode* root, int *max_size) {
        if (!root->left && !root->right) {
            return make_tuple(1, root->val, root->val);
        }

        int left_size = 0, left_min = root->val, left_max = root->val;
        if (root->left) {
            tie(left_size, left_min, left_max) = largestBSTSubtreeHelper(root->left, max_size);
        }

        int right_size = 0, right_min = root->val, right_max = root->val;
        if (root->right) {
            tie(right_size, right_min, right_max) = largestBSTSubtreeHelper(root->right, max_size);
        }

        int size = 0;
        if ((!root->left || left_size > 0) && 
            (!root->right || right_size > 0) &&
            left_max <= root->val && root->val <= right_min) {
            size = 1 + left_size + right_size;
            *max_size = max(*max_size, size);
        }

        return make_tuple(size, left_min, right_max);
    }
};

class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int res = 0, mn = INT_MIN, mx = INT_MAX;
        bool d = isValidBST(root, mn, mx, res);
        return res;
    }
    bool isValidBST(TreeNode *root, int &mn, int &mx, int &res) {
        if (!root) return true;
        int left_n = 0, right_n = 0;
        int left_mn = INT_MIN, left_mx = INT_MAX;
        int right_mn = INT_MIN, right_mx = INT_MAX;
        bool left = isValidBST(root->left, left_mn, left_mx, left_n);
        bool right = isValidBST(root->right, right_mn, right_mx, right_n);
        if (left && right) {
            if ((!root->left || root->val >= left_mx) && (!root->right || root->val <= right_mn)) {
                res = left_n + right_n + 1;
                mn = root->left ? left_mn : root->val;
                mx = root->right ? right_mx : root->val;
                return true;
            }
        }
        res = max(left_n, right_n);
        return false;
    }
};
