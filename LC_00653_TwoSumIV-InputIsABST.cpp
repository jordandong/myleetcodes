/*
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9
Output: True

Example 2:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28
Output: False
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

//T : O(N) , S : O(N)
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        set<int> st;
        return findTargetHelper(root, k, st);
    }

private:
    bool findTargetHelper(TreeNode* root, int k, set<int> &st) {
        if (!root)
            return false;        
        if (st.find(k - root->val) != st.end())
            return true;
        st.insert(root->val);
        if (findTargetHelper(root->left, k, st) || findTargetHelper(root->right, k, st))
            return true;
        return false;
    }
};

// T : O(N), S : O(logN)
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> lo, hi;
        TreeNode* lt = NULL, *ht = NULL;
        bool ls = false, hs = false;
        lo.push(root);
        hi.push(root);
        
        while (true) { 
            while (!ls && !lo.empty()) {
                lt = lo.top();
                lo.pop();
                if (!lt) {
                    if (!lo.empty()) {
                        lt = lo.top();
                        lo.pop();
                        lo.push(lt->right);
                        ls = true;
                    }
                } else {
                    lo.push(lt);
                    lo.push(lt->left);
                }
            }
            
            while (!hs && !hi.empty()) {
                ht = hi.top();
                hi.pop();
                if (!ht) {
                    if (!hi.empty()) {
                        ht = hi.top();
                        hi.pop();
                        hi.push(ht->left);
                        hs = true;
                    }
                } else {
                    hi.push(ht);
                    hi.push(ht->right);
                }
            }
            
            if (!lt || !ht || lt == ht)
                return false;
            int sum = lt->val + ht->val;
            if (sum == k)
                return true;
            else if (sum < k)
                ls = false;
            else
                hs = false;
        }
        return false;
    }
};

//T : O(N) , S : O(N)
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> st;
        findTargetHelper(root, k, st);
        int lo = 0, hi = st.size() - 1;
        while (lo < hi) {
            int sum = st[lo] + st[hi];
            if (sum == k)
                return true;
            if (sum < k)
                lo++;
            else
                hi--;
        }
        return false;
    }

private:
    void findTargetHelper(TreeNode* root, int k, vector<int> &st) {
        if (!root)
            return;
        findTargetHelper(root->left, k, st);
        st.push_back(root->val);
        findTargetHelper(root->right, k, st);
    }
};

//T : O(NlogN) , S : O(logN)
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        return findTargetHelper(root, root, k);
    }

private:
    bool findTargetHelper(TreeNode* cur, TreeNode* root, int k) {
        if (!cur)
            return false;
        int val = k - cur->val;
        TreeNode *t = root;
        while (t) {
            if (t->val == val && t != cur)
                return true;
            if (val < t->val)
                t = t->left;
            else
                t = t->right;
        }
        return findTargetHelper(cur->left, root, k) || findTargetHelper(cur->right, root, k);  
    }
};
