/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".

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
    bool isSymmetric(TreeNode *root) {
        if(!root)
            return true;
        return isSymmetricHelper(root->left, root->right);
    }
    bool isSymmetricHelper(TreeNode *l, TreeNode *r){
        if(!l || !r)
            return l == r;
        if(l->val != r->val)
            return false;
        return isSymmetricHelper(l->left, r->right) && isSymmetricHelper(l->right, r->left);
    }
};

//Non Recursion, S : O(logN)
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(root == NULL)
            return true;
        
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        
        s1.push(root->left);
        s2.push(root->right);
        
        while(s1.size() && s2.size()){
            TreeNode* n1 = s1.top();
            TreeNode* n2 = s2.top();
            s1.pop();
            s2.pop();
            if(n1 == n2)//both are NULL
                continue;
            if(!n1 || !n2)
                return n1 == n2;
                
            if(n1->val != n2->val)
                return false;
            
            s1.push(n1->left);
            s1.push(n1->right);
            s2.push(n2->right);
            s2.push(n2->left);
        }
        
        if(s1.size() || s2.size())
            return false;
        return true;
    }
};
