/*
Given a binary tree, you need to find the length of Longest Consecutive Path in Binary Tree.
Especially, this path can be either increasing or decreasing.
For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is not valid.
On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.

Example 1:
Input:
        1
       / \
      2   3
Output: 2
Explanation: The longest consecutive path is [1, 2] or [2, 1].

Example 2:
Input:
        2
       / \
      1   3
Output: 3
Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
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
    int longestConsecutive(TreeNode* root) {
        int maxlen = 0;
        dfs(root, maxlen);
        return maxlen;
    }

private:
    vector<int> dfs(TreeNode* node, int& maxlen) {
        if (!node)
            return {0,0};

        vector<int> p(2, 1);
        int l2r = 1;
        int r2l = 1;

        if (node->left) {
            vector<int> l = dfs(node->left, maxlen);
            int lv = node->left->val;
            if (node->val + 1 == lv) {
                p[0] = max(p[0], 1 + l[0]);
                r2l += l[0];
            }
            if (node->val - 1 == lv) {
                p[1] = max(p[1], 1 + l[1]);
                l2r += l[1];
            }
        }

        if (node->right) {
            vector<int> r = dfs(node->right, maxlen);
            int rv = node->right->val;
            if (node->val + 1 == rv) {
                p[0] = max(p[0], 1 + r[0]);
                l2r += r[0];
            }
            if (node->val - 1 == rv) {
                p[1] = max(p[1], 1 + r[1]);
                r2l += r[1];
            }
        }
        maxlen = max(maxlen, max(max(l2r, r2l), max(p[0], p[1])));
        return p;
    }
};

int main() {
	// your code goes here
	TreeNode *root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	Solution s;
	cout<<s.longestConsecutive(root)<<endl;
	return 0;
}
