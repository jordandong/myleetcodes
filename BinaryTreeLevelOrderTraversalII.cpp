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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int> > res;
        
        vector<int> tmp;
        queue<TreeNode*> tmpq;
        
        if(root==NULL)
            return res;
        
        while(!q.empty()){
            TreeNode *tn = q.front();
            q.pop();
            tmp.push_back(tn->val);
            if(tn->left!=NULL)
                tmpq.push(tn->left);
            if(tn->right!=NULL)
                tmpq.push(tn->right);
                
            if(q.empty())
            {
                res.push_back(tmp);
                tmp.clear();
                while(!tmpq.empty()){
                    q.push(tmpq.front());
                    tmpq.pop();
                }
            }
        }
        
        vector<vector<int> > res1;
        
        while(!res.empty()){
            res1.push_back(res.back());
            res.pop_back();
        }
            
        
        return res1;
    }
};
