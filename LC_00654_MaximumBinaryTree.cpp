/*
Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:
1. The root is the maximum number in the array.
2. The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
3. The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.

Construct the maximum tree by the given array and output the root node of this tree.

Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:
      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
Note:
1. The size of the given array will be in the range [1,1000].
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

// T : O(NlogN) , S: O(logN)
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTreeHelper(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* constructMaximumBinaryTreeHelper(vector<int>& nums, int lo, int hi) {
        if (lo > hi)
            return NULL;
        int mx = nums[lo], mid = lo;
        for (int i = lo; i <= hi; i++) {
            if(mx < nums[i]) {
                mx = nums[i];
                mid = i;
            }
        }
        TreeNode *t = new TreeNode(mx);
        t->left = constructMaximumBinaryTreeHelper(nums, lo, mid -1);
        t->right = constructMaximumBinaryTreeHelper(nums, mid + 1, hi);
        return t;
    }
};

//T : O(N), S : O(N)
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> stk;
        for (int i = 0; i < nums.size(); ++i) {
            TreeNode* cur = new TreeNode(nums[i]);
            TreeNode* l = NULL;
            while (!stk.empty() && stk.back()->val < nums[i]) {
                l = stk.back();
                stk.pop_back();
            }
            cur->left = l;
            if (!stk.empty())
                stk.back()->right = cur;
            stk.push_back(cur);
        }
        return stk.front();
    }
};
