/*
You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins in total throughout the whole tree.

In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.

Return the minimum number of moves required to make every node have exactly one coin.

Example 1:
     3
 0       0

Input: root = [3,0,0]
Output: 2
Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.

Example 2:
     0
 3       0

Input: root = [0,3,0]
Output: 3
Explanation: From the left child of the root, we move two coins to the root [taking two moves]. Then, we move one coin from the root of the tree to the right child.

Example 3:
    1
 0     2
 
Input: root = [1,0,2]
Output: 2

Example 4:
     1
 0       0
 
Input: root = [1,0,0,null,3]
Output: 4
 
Constraints:
The number of nodes in the tree is n.
1 <= n <= 100
0 <= Node.val <= n
The sum of all Node.val is n.
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
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        distributeCoinsHelper(root, ans);
        return ans;
    }
    
    int distributeCoinsHelper(TreeNode* root, int &ans) {
        if (!root) {
            return 0;
        }
        int l = distributeCoinsHelper(root->left, ans);
        int r = distributeCoinsHelper(root->right, ans);
        ans += abs(l) + abs(r);
        return root->val + l + r - 1;
    }
};
