/*
You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis.
The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

You always start to construct the left child node of the parent first if it exists.

Example:
Input: "4(2(3)(1))(6(5))"
Output: return the tree root node representing the following tree:
       4
     /   \
    2     6
   / \   / 
  3   1 5   

Note:
1. There will only be '(', ')', '-' and '0' ~ '9' in the input string.
2. An empty tree is represented by "" instead of "()".

Hide Tags Tree String
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
    TreeNode* str2tree(string s) {
        int i = 0;
        return s.size() == 0 ? NULL : str2treeHelper(s, i);
    }

private:
    TreeNode* str2treeHelper(string& s, int& i) {
        int start = i;
        if (s[i] == '-')
            i++;
        while (isdigit(s[i]))
            i++;
        int num = stoi(s.substr(start, i - start));
        TreeNode* node = new TreeNode(num);
        if (s[i] == '(') {
            node->left = str2treeHelper(s, ++i);
            i++;    // )
        }
        if (s[i] == '(') {
            node->right = str2treeHelper(s, ++i);
            i++;    // )
        }
        return node;
    }
};
