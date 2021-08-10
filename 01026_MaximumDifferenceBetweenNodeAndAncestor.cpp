/*
Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.

Example 1:
               8
    3                      10
1         6                        14 
       4     7                   13

Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.

Example 2:

    1
          2
                0
             3
 
Input: root = [1,null,2,null,0,3]
Output: 3
 
Constraints:
The number of nodes in the tree is in the range [2, 5000].
0 <= Node.val <= 105
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
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        if (!root) {
            return ans;
        }
        maxAncestorDiffHelper(root, root->val, root->val, ans);
        return ans;
    }
    
    void maxAncestorDiffHelper(TreeNode* root, int mx, int mi, int &ans) {
        if (!root) {
            return;
        }
        int ans_temp = max(abs(mx - root->val), abs(mi - root->val));
        ans = max(ans, ans_temp);
        maxAncestorDiffHelper(root->left, max(mx, root->val), min(mi, root->val), ans);
        maxAncestorDiffHelper(root->right, max(mx, root->val), min(mi, root->val), ans);
    }
};

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return maxAncestorDiffHelper(root, root->val, root->val);
    }
    
    int maxAncestorDiffHelper(TreeNode* root, int mx, int mi) {
        if (!root) {
            return mx - mi;
        }
        int ans1 = maxAncestorDiffHelper(root->left, max(mx, root->val), min(mi, root->val));
        int ans2 = maxAncestorDiffHelper(root->right, max(mx, root->val), min(mi, root->val));
        return max(ans1, ans2);
    }
};
