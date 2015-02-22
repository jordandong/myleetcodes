/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

Hide Tags Tree Depth-first Search
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//Recursion
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(!p || !q)
            return p == q;
        if(p->val != q->val)
            return false;
        else
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

//Non Recursion
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        queue<TreeNode*> q_p;
        queue<TreeNode*> q_q;
        q_p.push(p);
        q_q.push(q);
        while(q_p.size() && q_q.size()){
            TreeNode *p_tmp = q_p.front();
            q_p.pop();
            TreeNode *q_tmp = q_q.front();
            q_q.pop();
            if(!p_tmp || !q_tmp){
                if(p_tmp != q_tmp)
                    return false;
                else
                    continue;
            }
            if(p_tmp->val != q_tmp->val)
                return false;
            q_p.push(p_tmp->left);
            q_p.push(p_tmp->right);
            q_q.push(q_tmp->left);
            q_q.push(q_tmp->right);
        }
        return true;
    }
};
