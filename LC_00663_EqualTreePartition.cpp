/*
Given a binary tree with n nodes, 
your task is to check if it's possible to partition the tree to two trees which have the equal sum of values after removing exactly one edge on the original tree.

Example 1:
Input:     
    5
   / \
  10 10
    /  \
   2   3

Output: True

Explanation: 
    5
   / 
  10
Sum: 15

   10
  /  \
 2    3
Sum: 15

Example 2:
Input:     
    1
   / \
  2  10
    /  \
   2   20

Output: False

Explanation: You can't split the tree into two trees with equal sum after removing exactly one edge on the tree.

Note:
1. The range of tree node value is in the range of [-100000, 100000].
2. 1 <= n <= 10000
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
    bool checkEqualTree(TreeNode* root) {
        bool found = false;
        int sum = checkEqualTreeSum(root);
        checkEqualTreeHelper(root, found, sum);
        return found;
    }
    
    int checkEqualTreeHelper(TreeNode* root, bool &found, int sum) {
        if (!root)
            return 0;
        int l = checkEqualTreeHelper(root->left, found, sum);
        if (found)
            return l;
        int r = checkEqualTreeHelper(root->right, found, sum);
        if (found)
            return r;
        if ((root->left && l == sum - l) || (root->right && r == sum - r))
            found = true;
        return l + r + root->val;
    }
    
    int checkEqualTreeSum(TreeNode* root) {
        if (!root)
            return 0;
        return checkEqualTreeSum(root->left) + checkEqualTreeSum(root->right) + root->val;
    }
};

class Solution {
public:
    bool checkEqualTree(TreeNode* root) {
        set<int> sums;
        int sum = subTreeSums(root, root, sums);
        return abs(sum) % 2 == 1 ? false : (sums.find(sum / 2) != sums.end());
    }

private:
    int subTreeSums(TreeNode* node, TreeNode* root, set<int> &sums) {
        if (!node)
            return 0;
        int l = subTreeSums(node->left, root, sums);
        int r = subTreeSums(node->right, root, sums);
        int sum = node->val + l + r;
        if (node != root)
            sums.insert(sum);
        return sum;
    }
};

class Solution {
public:
    bool checkEqualTree(TreeNode* root) {
        map<int, int> sums;
        int sum = subTreeSums(root, sums);
        return abs(sum) % 2 == 1 ? false : sum == 0 ? sums[0] > 1 : sums.count(sum / 2) > 0;
    }

private:
    int subTreeSums(TreeNode* node, map<int, int>& sums) {
        if (!node)
            return 0;
        int l = subTreeSums(node->left, sums);
        int r = subTreeSums(node->right, sums);
        int sum = node->val + l + r;
        sums[sum]++;
        return sum;
    }
};
