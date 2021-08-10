/*
Given the root of a binary search tree, and an integer k, return the kth (1-indexed) smallest element in the tree.

Example 1:

      3
 1         4
    2

Input: root = [3,1,4,null,2], k = 1
Output: 1

Example 2:

                     5
              3             6
          2      4
       1

Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
 

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?
*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        kthSmallestHelp(root, k, ans);
        return ans;
    }
    
    void kthSmallestHelp(TreeNode* root, int &k, int &ans) {
        if (!root) {
            return;
        }
        kthSmallestHelp(root->left, k, ans);
        if (--k <= 0) {
            if (k == 0) {
                ans = root->val;
            }
            return;
        }
        kthSmallestHelp(root->right, k, ans);
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return kthSmallestHelper(root, k);
    }
    int kthSmallestHelper(TreeNode* root, int &k) {
        if (!root)
            return -1;
        int l = kthSmallestHelper(root->left, k);
        if (k == 0)
            return l;
        if(--k == 0)
            return root->val;
        return kthSmallestHelper(root->right, k);
    }
};
