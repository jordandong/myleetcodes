/*
Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:
Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:
Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:
Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:
Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).


Note: Answer will in the range of 32-bit signed integer.
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
    int widthOfBinaryTree(TreeNode* root) {
        unordered_map<int, int> l, r;
        widthOfBinaryTreeHelper(root, 1, 1, l, r);
        int res = 0;
        for (auto p : l) {
            res = max(res, r[p.first] - p.second + 1);
        }
        return res;
    }
    
    void widthOfBinaryTreeHelper(TreeNode* root, int lv, int idx, 
                                unordered_map<int, int> &l, unordered_map<int, int> &r) {
        if (!root)
            return;
        
        if (l.find(lv) != l.end()) {
            l[lv] = min(l[lv], idx);
        } else {
            l[lv] = idx;    
        }
        
        if (r.find(lv) != r.end()) {
            r[lv] = max(r[lv], idx);
        } else {
            r[lv] = idx;    
        }
        
        widthOfBinaryTreeHelper(root->left, lv + 1, idx * 2, l, r);
        widthOfBinaryTreeHelper(root->right, lv + 1, idx * 2 + 1, l, r);
    }  
};
