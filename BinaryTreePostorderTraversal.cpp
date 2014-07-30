/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
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
 
 /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> rtn;
        stack<TreeNode*> stk;
        stack<bool> visited;
        stk.push(root);
        visited.push(false);
        while(!stk.empty()){
            TreeNode* cur=stk.top();
            bool v = visited.top();
            stk.pop();
            visited.pop();
            if(!cur || v){
                if(v)
                    rtn.push_back(cur->val);
                continue;
            }
            stk.push(cur);
            visited.push(true);
            stk.push(cur->right);
            visited.push(false);
            stk.push(cur->left);
            visited.push(false);
        }
        return rtn;
    }
};
 
 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> s;
        //postorderHelper(root, s);
        postorderHelper1(root, s);
        return s;
    }
    
    void postorderHelper(TreeNode *root, vector<int> &s){
        if(!root)
            return;
        postorderHelper(root->left, s);
        postorderHelper(root->right, s);
        s.push_back(root->val);
    }
    
    void postorderHelper1(TreeNode *root, vector<int> &s){
        stack<TreeNode*> stk;
        set<TreeNode*> st;
        while(!stk.empty() || root){
            while(root){
                stk.push(root);
                root=root->left;
            }
            
            root = stk.top();
            while(st.find(root)!=st.end()){
                stk.pop();
                s.push_back(root->val);
                if(!stk.empty())
                    root = stk.top();
                else
                    return;
            }
            st.insert(root);
            root = root->right;
        }
    }
};
