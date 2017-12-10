/*
Given a binary tree where every node has a unique value, and a target key k, find the closest leaf node to target k in the tree.

A node is called a leaf if it has no children.

In the following examples, the input tree is represented in flattened form row by row.
The actual root tree given will be a TreeNode object.

Example 1:
Input:
root = [1, 3, 2], k = 1
Diagram of binary tree:
          1
         / \
        3   2

Output: 2 (or 3)
Explanation: Either 2 or 3 is the closest leaf node to 1.

Example 2:
Input:
root = [1], k = 1
Output: 1
Explanation: The closest leaf node is the root node itself.

Example 3:
Input:
root = [1,2,3,4,null,null,null,5,null,6], k = 2
Diagram of binary tree:
             1
            / \
           2   3
          /
         4
        /
       5
      /
     6

Output: 3
Explanation: The leaf node with value 3 (and not the leaf node with value 6) is closest to the node with value 2.

Note:
1. root represents a binary tree with at least 1 node and at most 1000 nodes.
2. Every node has a unique node.val in range [1, 1000].
3. There exists some node in the given binary tree for which node.val == k.
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
    int findClosestLeaf(TreeNode* root, int k) {
        set<int> leaf, visited;
        vector<int> g[1001];
        dfs(root, leaf, visited, g);
        queue<int> Q;
        Q.push(k);
        visited.insert(k);
        while (!Q.empty()) {
            int val = Q.front();
            Q.pop();
            if (leaf.find(val) != leaf.end())
                return val;
            for (auto v : g[val]) {
                if (visited.find(v) == visited.end()) {
                    visited.insert(v);
                    Q.push(v);
                }
            }
        }
        return 0;
    }
private:
    void dfs(TreeNode* root, set<int> &leaf, set<int> &visited, vector<int>* g) {
        if ((!root -> left) && (!root -> right)) {
            leaf.insert(root -> val);
            return;
        }
        if (root -> left) {
            g[root -> val].push_back(root -> left -> val);
            g[root -> left -> val].push_back(root -> val);
            dfs(root -> left, leaf, visited, g);
        }
        if (root -> right) {
            g[root -> val].push_back(root -> right -> val);
            g[root -> right -> val].push_back(root -> val);
            dfs(root -> right, leaf, visited, g);
        }
    }
};
