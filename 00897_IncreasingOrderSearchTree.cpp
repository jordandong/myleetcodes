/*
Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

Example 1:
       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \ 
1        7   9


 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
            \
             7
              \
               8
                \
                 9  
Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

Example 2:
    5
  /    \
1       7

1
  \
    5
      \
        7
Input: root = [5,1,7]
Output: [1,null,5,null,7]

Constraints:

The number of nodes in the given tree will be in the range [1, 100].
0 <= Node.val <= 1000
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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(-1);
        TreeNode* ans = dummy;
        increasingBSTHelper(root, dummy);
        return ans->right;
    }
    void increasingBSTHelper(TreeNode* root, TreeNode* &dummy) {
        if (!root) {
            return;
        }
        increasingBSTHelper(root->left, dummy);
        root->left = NULL;
        dummy->right = root;
        dummy = dummy->right;
        increasingBSTHelper(root->right, dummy);   
    }
};

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) {
            return root;
        }
        TreeNode* tail = NULL, *head = NULL;
        stack<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            TreeNode* cur = nodes.top();
            nodes.pop();
            if (!cur->left && !cur->right) {
                if (!tail) {
                    head = cur;
                    tail = cur;
                } else {
                    tail->right = cur;
                    tail = tail->right; 
                }
            } else {
                if (cur->right) {
                    nodes.push(cur->right);
                    cur->right = NULL;
                }
                TreeNode* tmp = cur->left;
                cur->left = NULL;
                nodes.push(cur);
                if (tmp) {
                    nodes.push(tmp);
                }
            }
        }
        return head;
    }
};

