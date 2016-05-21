/*
Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Note:
Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
 
Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?

Hint:
1. Consider implement these two helper functions:
   getPredecessor(N), which returns the next smaller node to N.
   getSuccessor(N), which returns the next larger node to N.
2. Try to assume that each node has a parent pointer, it makes the problem much easier.
3. Without parent pointer we just need to keep track of the path from the root to the current node using a stack.
4. You would need two stacks to track the path in finding predecessor and successor node separately.
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

//T : O(N + Nlogk), S : O(k)
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        priority_queue<pair<double, int>> pq;
        closestK(root, pq, target, k);
        vector<int> closest;
        while (!pq.empty()) {
            closest.push_back(pq.top().second);
            pq.pop();
        }
        return closest;
    }
private:
    void closestK(TreeNode* node, priority_queue<pair<double, int>>& pq, double target, int k) {
        if (!node)
            return;
        pq.push(make_pair(abs(target - node->val), node->val));
        if (pq.size() > k)
            pq.pop();
        closestK(node->left, pq, target, k);
        closestK(node->right, pq, target, k);
    }
};

//T : O(N), S : O(N)
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> closest(k);
        stack<int> pre, suc;
        inorder(root, target, false, pre);
        inorder(root, target, true, suc);
        for (int i = 0; i < k; i++) {
            if (pre.empty()) {
                closest[i] = suc.top();
                suc.pop();
            } else if (suc.empty()) {
                closest[i] = pre.top();
                pre.pop();
            } else if (abs(target - pre.top()) < abs(target - suc.top())) {
                closest[i] = pre.top();
                pre.pop();
            } else {
                closest[i] = suc.top();
                suc.pop();
            }
        }
        return closest;
    }
private:
    void inorder(TreeNode* root, double target, bool reversed, stack<int>& s) {
        if (!root)
            return;
        inorder(reversed ? root->right : root->left, target, reversed, s);
        if ((reversed && root->val <= target) || (!reversed && root->val > target))
            return;
        s.push(root -> val);
        inorder(reversed ? root->left : root->right, target, reversed, s);
    }
};
